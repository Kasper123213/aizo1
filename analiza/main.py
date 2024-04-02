import matplotlib.pyplot as plt
from numpy import mean, linspace
from scipy.interpolate import make_interp_spline
def readFile(filename):
    try:
        with open(filename, 'r') as file:
            times = file.read()
            return times

    except FileNotFoundError:
        print(f"Plik {filename} nie został znaleziony.")
    except Exception as e:
        print(f"Wystąpił błąd podczas wczytywania pliku {filename}: {e}")

# def makeList(content):
#     return [[int(l) for l in line.split(";")] for line in content.split("\n")[:-1]]
def makeList(content):
    avg = []
    content = content.split("\n")[:-1]
    content = [l.split(";") for l in content]

    for i in range(len(content)):
        content[i] = [int(l) for l in content[i]]
        avg.append(mean(content[i]))

    return content, avg




insertionSorti = readFile("wyniki/insertionSorti.csv")
insertionSorti, iSiAVG = makeList(insertionSorti)

insertionSortf = readFile("wyniki/insertionSortf.csv")
insertionSortf, iSfAVG = makeList(insertionSortf)


binaryInsertionSorti = readFile("wyniki/binaryInsertionSorti.csv")
binaryInsertionSorti, bSiAVG = makeList(binaryInsertionSorti)

binaryInsertionSortf = readFile("wyniki/binaryInsertionSortf.csv")
binaryInsertionSortf, bSfAVG = makeList(binaryInsertionSortf)



heapSorti = readFile("wyniki/heapSorti.csv")
heapSorti, hSiAVG = makeList(heapSorti)

heapSortf = readFile("wyniki/heapSortf.csv")
heapSortf, hSfAVG = makeList(heapSortf)


quickSorti = readFile("wyniki/quickSorti.csv")
quickSorti, qSiAVG = makeList(quickSorti)

quickSortf = readFile("wyniki/quickSortf.csv")
quickSortf, qSfAVG = makeList(quickSortf)

titles = ["random", "descending", "sorted 100%", "sorted 66%", "sorted 33%"]
#1 full random
#   30 000  #100 pomiarow
#   50 000  #100 pomiarow
#   70 000  #100 pomiarow
#   90 000  #100 pomiarow
#   110 000 #100 pomiarow
#   130 000 #100 pomiarow
#   150 000 #100 pomiarow
#2 Descending
#   ...     #100 pomiarow
#3 sorted 100
#           #100 pomiarow
#3 sorted 66
#           #100 pomiarow
#3 sorted 33
#   ...     #100 pomiarow


x = range(30_000, 150_001, 20_000)
for i in range(1,2):
# for i in range(5):
    y = iSiAVG[(i)*7:(i+1)*7]

    X_Y_Spline = make_interp_spline(x, y)
    X_ = linspace(30_000, 150_000, 50)
    Y_ = X_Y_Spline(X_)

    plt.figure()
    plt.plot(X_, Y_)
    plt.plot(X_, X_**2/250000, label="x**2")
    plt.legend()
    plt.title(titles[i])
plt.show()


