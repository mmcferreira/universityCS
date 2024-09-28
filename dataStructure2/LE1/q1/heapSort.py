import time
import random

def generate_random_array(size, start=1, end=100000):
    return random.sample(range(start, end), size)

def reHeapDown(lista, index, end):
    left_child = 2 * index + 1
    right_child = 2 * index + 2
    largest = index

    if left_child <= end and lista[left_child] > lista[largest]:
        largest = left_child
    if right_child <= end and lista[right_child] > lista[largest]:
        largest = right_child

    if largest != index:
        lista[index], lista[largest] = lista[largest], lista[index]
        reHeapDown(lista, largest, end)

def buildHeap(lista):
    n = len(lista)
    for i in range((n // 2) - 1, -1, -1):
        reHeapDown(lista, i, n - 1)

def heapSort(lista):
    buildHeap(lista)
    end = len(lista) - 1
    while end > 0:
        lista[0], lista[end] = lista[end], lista[0]
        end -= 1
        reHeapDown(lista, 0, end)
    return lista

# Medindo o tempo
random_array = generate_random_array(50000)
start_time = time.time()
sorted_array = heapSort(random_array)
end_time = time.time()
print(sorted_array)
print(f"Heap Sort: {end_time - start_time:.6f} segundos")
