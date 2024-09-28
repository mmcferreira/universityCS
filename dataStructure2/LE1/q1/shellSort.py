import time
import random

def generate_random_array(size, start=1, end=100000):
    return random.sample(range(start, end), size)

def shell_sort(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr

# Medindo o tempo
random_array = generate_random_array(50000)
start_time = time.time()
sorted_array = shell_sort(random_array)
end_time = time.time()
print(sorted_array)
print(f"Shell Sort: {end_time - start_time:.6f} segundos")
