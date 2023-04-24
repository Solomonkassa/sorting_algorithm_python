def bitonic_sort(arr, up=True):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = bitonic_sort(arr[:mid], True)
    right = bitonic_sort(arr[mid:], False)
    arr = left + right

    return bitonic_merge(arr, up)

def bitonic_merge(arr, up=True):
    if len(arr) <= 1:
        return arr

    comp = lambda x, y: x > y if up else x < y
    mid = len(arr) // 2

    # compare elements in the first half with the corresponding element in the second half
    for i in range(mid):
        if comp(arr[i], arr[i + mid]):
            arr[i], arr[i + mid]
