from random import randint

def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i 
        for j in range(i + 1, len(arr)): 
            if arr[min_idx] > arr[j]: 
                min_idx = j 
                        
        arr[i], arr[min_idx] = arr[min_idx], arr[i] 

arr = []
for _ in range(20):
    arr.append(randint(0, 100))

print("Before: ", arr)
selection_sort(arr)
print("After : ", arr)
