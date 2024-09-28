import time
import random

def generate_random_array(size, start=1, end=100000):
    return random.sample(range(start, end), size)

def partition(lista, start, end):
    pivot = lista[end]
    current = start - 1
    swaper = start
    while swaper <= end - 1:
        if lista[swaper] <= pivot:
            current += 1
            lista[current], lista[swaper] = lista[swaper], lista[current]
        swaper += 1
    lista[current + 1], lista[end] = lista[end], lista[current + 1]
    return current + 1

def quick_sort(lista, start, end):
    if start < end:
        pivotposition = partition(lista, start, end)
        quick_sort(lista, start, pivotposition - 1)
        quick_sort(lista, pivotposition + 1, end)
    return lista

# Medindo o tempo
random_array = generate_random_array(50000)
start_time = time.time()
sorted_array = quick_sort(random_array, 0, len(random_array) - 1)
end_time = time.time()
print(sorted_array)
print(f"Quick Sort: {end_time - start_time:.6f} segundos")
