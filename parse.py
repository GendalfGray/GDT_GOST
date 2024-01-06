from bs4 import BeautifulSoup as bs
import requests

FIELDS = ["a",  "b",  "c",    "cd",
          "d",  "e",  "ef",   "f",    
          "fg", "g",  "h",    "h7",   
          "h14","js", "js7",  "js14",
          "j",  "k",  "m",    "n",    
          "p",  "r",  "s",    "t",     
          "u",  "v",  "x",    "y",    
          "z",  "za", "zb",   "zc"]

DIM_RANGE = [[0, 3],        [3, 6],         [6, 10],        [10, 18],
             [18, 30],      [30, 50],       [50, 80],       [80, 120],
             [120, 180],    [180, 250],     [250, 315],     [315, 400],
             [400, 500],    [500, 630],     [630, 800],     [800, 1000],
             [1000, 1250],  [1250, 1600],   [1600, 2000],   [2000, 2500],
             [2500, 3150]]


def list_of_tolerance(field, dimension, tol_size):
    out = {}
    out["field"]     = field
    out["min_size"]  = dimension[0]
    out["max_size"]  = dimension[1]
    out["start_tol"] = tol_size[0]
    out["end_tol"]   = tol_size[1]
    return out

def minmax_tol(value):
    symbol_id = 0
    print(value)
    if(value == "blank"):
        return ["blank", "blank"]
    try:
        symbol_id = value.index("+", 1)
    except ValueError:
        try:
            symbol_id = value.index("-", 1)
        except ValueError:
            return ["error was", "here"]

    start_tol = value[:symbol_id]
    end_tol = value[symbol_id:]
    return [start_tol, end_tol]

def nominal_sizes(list_of_sizes):
    all_size_ranges = []
    for s in list_of_sizes:
        size_range = []
        for size in s.split(" "):
            try:
                size_range.append(int(size))
                continue
            except ValueError:
                continue
        if (len(size_range) == 1):
            tem = size_range[0]
            size_range[0] = 0
            size_range.append(tem)
        
        all_size_ranges.append(size_range)
    return all_size_ranges

final_result = []

for adr in FIELDS:
    respo = requests.get(f"http://tekhnar.ru/dopuski-posadki/otv-{adr}.html")
    print(adr)
    soup = bs(respo.text, 'html.parser')

    # h7, js7 ...
    tolerance_fields = []
    for _ in soup.find_all('th'):
        pass
        tolerance_fields.append(_.text)

    # cleanup
    tolerance_fields = tolerance_fields[1:len(tolerance_fields)-1]

    # +0.03 -0.045 ...
    tolerance_sizes = []
    for _ in soup.find_all('td'):
        pass
        if (_.text == ""):
            tolerance_sizes.append("blank")
        else: 
            tolerance_sizes.append(_.text)

    #print(len(tolerance_fields))
    tolerances_sorted_by_nominal_size = []
    while (len(tolerance_sizes)>0):
        tolerances_sorted_by_nominal_size.append(tolerance_sizes[0:len(tolerance_fields)+1])
        del tolerance_sizes[0:len(tolerance_fields)+1]


    tolerance_sizes_range = []
    for _ in tolerances_sorted_by_nominal_size:
        tolerance_sizes_range.append(_[0])

    #print(tolerance_sizes_range)

    collection_all_data = []

    nominal_sizes_range = nominal_sizes(tolerance_sizes_range)

    #print(tolerance_fields)
    #print(nominal_sizes_range)
    #print(tolerances_sorted_by_nominal_size)
    
    
    for i, field in enumerate(tolerance_fields):
        for j, size in enumerate(tolerances_sorted_by_nominal_size):
            #print(field, nominal_sizes_range[int(j)])
            #print(size)
            #print(f"i = {i}")
            #print(size[1:][int(i)])
            final_result.append(list_of_tolerance(field, nominal_sizes_range[int(j)], minmax_tol(size[1:][int(i)])))
            pass

with open('hole.csv', 'w', encoding="utf-8") as f:

    for i, struct in enumerate(final_result):

        f.write(f"{final_result[i]['field']}, {final_result[i]['min_size']}, {final_result[i]['max_size']}, {final_result[i]['start_tol']}, {final_result[i]['end_tol']}\n" )