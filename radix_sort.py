def radix_sort(arr):
    radix = 10
    max_length = False
    tmp, placement = -1, 1

    while not max_length:
        max_length = True
        # declare and initialize buckets
        buckets = [list() for _ in range(radix)]

        # split arr between lists
        for i in arr:
            tmp = i // placement
            buckets[tmp % radix].append(i)
            if max_length and tmp > 0:
                max_length = False

        # empty lists into arr array
        a = 0
        for b in range(radix):
            bucket = buckets[b]
            for i in bucket:
                arr[a] = i
                a += 1

        # move to next digit
        placement *= radix
    return arr
