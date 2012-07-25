# ANDROUND test case generator

import sys
import random
import argparse


MAXT = 50
MAXN = 200000
MAXK = 1000000000
MAXA = 1000000000


def biased(lo, hi, mode=None):
    return int(round(random.triangular(lo, hi, mode)))


def generate(N, K, maxA=MAXA, minA=1):
    return (N, K, [random.randint(minA, maxA) for i in range(N)])


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('tests', metavar='T', type=int,
            help="number of tests to output")
    parser.add_argument('filename', type=str, nargs='?',
            default="andround.in", help="filename to output to")
    parser.add_argument('--size', metavar='N', type=int, nargs='*',
            help="number of integers in array A")
    parser.add_argument('--cycles', metavar='K', type=int, nargs='*',
            help="number of times to repeat AND operation")
    parser.add_argument('-a', type=int, nargs='*',
            help="maximum element allowed in array A")
    args = parser.parse_args()
    
    if args.size is None:
        args.size = []
    if args.cycles is None:
        args.cycles = []
    if args.a is None:
        args.a = []

    for l in (args.size, args.cycles, args.a):
        deficit = args.tests - len(l)
        for i in range(deficit):
            if l is args.size:
                l.append(biased(1, MAXN, MAXA))
            elif l is args.cycles:
                l.append(biased(1, MAXK, MAXK))
            else:
                l.append(biased(1, MAXA, MAXA))

    with open(args.filename, 'w') as fout:
        print >>fout, args.tests
        for i in range(args.tests):
            N, K, A = generate(args.size[i], args.cycles[i], maxA=args.a[i])
            print >>fout, N, K
            print >>fout, ' '.join(map(str, A))
        
        


if __name__ == '__main__':
    main()
