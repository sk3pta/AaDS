


# CONSTS

m = 13


def h1(x):
    return ( x % m)

def h2(x):
    return (x % (m - 1) + 1) % m

def h(x,i):
    return (h1(x) + i * h2(x)) % m

def main():
    INPUT = [46, 40, 48, 15, 34, 11, 72, 22, 74, 75, 50,6, 65]
    OUTPUT = dict()

    for value in INPUT:
        i = 0
        key = h(value,i)
        while key in OUTPUT:
            i += 1
            key = h(value, i)
        OUTPUT[key] = value

    print(dict(sorted(OUTPUT.items())))


if __name__ == "__main__":
    main()