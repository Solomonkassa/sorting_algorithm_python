def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    
    pivot = arr[-1]
    left = []
    right = []
    
    for element in arr[:-1]:
        if element <= pivot:
            left.append(element)
        else:
            right.append(element)
    
    return quick_sort(left) + [pivot] + quick_sort(right)
