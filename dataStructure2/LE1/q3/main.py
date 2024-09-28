import random
import time

def count_sort(input_array):
    M = max(input_array)
    count_array = [0] * (M + 1)
    comparisons = 0
    swaps = 0

    for num in input_array:
        count_array[num] += 1

    for i in range(1, M + 1):
        count_array[i] += count_array[i - 1]

    output_array = [0] * len(input_array)

    for i in range(len(input_array) - 1, -1, -1):
        output_array[count_array[input_array[i]] - 1] = input_array[i]
        count_array[input_array[i]] -= 1
        swaps += 1

    # Adicionando contagem de comparações
    comparisons += len(input_array)  # Contar a iteração sobre o input_array
    comparisons += M + 1  # Contar a iteração sobre o count_array

    return output_array, comparisons, swaps

def counting_sort_for_radix(arr, exp1):
    n = len(arr)
    output = [0] * n
    count = [0] * 10
    comparisons = 0
    swaps = 0

    for i in range(n):
        index = arr[i] // exp1
        count[index % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = arr[i] // exp1
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        swaps += 1
        comparisons += 1  # Contar a comparação
        i -= 1

    for i in range(len(arr)):
        arr[i] = output[i]
        swaps += 1

    return comparisons, swaps

def radix_sort(arr):
    max1 = max(arr)
    exp = 1
    total_comparisons = 0
    total_swaps = 0
    while max1 / exp >= 1:
        comparisons, swaps = counting_sort_for_radix(arr, exp)
        total_comparisons += comparisons
        total_swaps += swaps
        exp *= 10
    return total_comparisons, total_swaps

def insertion_sort(bucket):
    comparisons = 0
    swaps = 0
    for i in range(1, len(bucket)):
        key = bucket[i]
        j = i - 1
        while j >= 0 and bucket[j] > key:
            bucket[j + 1] = bucket[j]
            j -= 1
            comparisons += 1
            swaps += 1
        bucket[j + 1] = key
        swaps += 1
    return comparisons, swaps

def bucket_sort(arr):
    n = len(arr)
    buckets = [[] for _ in range(n)]
    comparisons = 0
    swaps = 0

    for num in arr:
        bi = int(n * num)
        buckets[bi].append(num)

    for bucket in buckets:
        if len(bucket) > 0:  # Verifica se o balde não está vazio
            comp, swap = insertion_sort(bucket)
            comparisons += comp
            swaps += swap

    index = 0
    for bucket in buckets:
        for num in bucket:
            arr[index] = num
            index += 1
            swaps += 1

    return comparisons, swaps

if __name__ == "__main__":
    #gera vetor de 100 mil unidades aleatórias, usado para comparar
    size = 100000
    arr = [random.randint(0, 100000) for _ in range(size)]

    #medição de tempo
    start_time = time.time()
    sorted_count, count_comparisons, count_swaps = count_sort(arr.copy())
    count_time = time.time() - start_time

    start_time = time.time()
    sorted_radix = arr.copy()
    radix_comparisons, radix_swaps = radix_sort(sorted_radix)
    radix_time = time.time() - start_time

    arr_float = [random.random() for _ in range(size)]  # Valores entre 0 e 1
    start_time = time.time()
    bucket_comparisons, bucket_swaps = bucket_sort(arr_float)
    bucket_time = time.time() - start_time

    #exibição de resultados
    print(f"Tamanho do vetor: {size} elementos\n")
    print(f"{'Algoritmo':<15} {'Tempo (s)':<15} {'Comparações':<15} {'Trocas':<15}")
    print("------------------------------------------------------------")
    print(f"{'Counting Sort':<15} {count_time:<15.6f} {count_comparisons:<15} {count_swaps:<15}")
    print(f"{'Radix Sort':<15} {radix_time:<15.6f} {radix_comparisons:<15} {radix_swaps:<15}")
    print(f"{'Bucket Sort':<15} {bucket_time:<15.6f} {bucket_comparisons:<15} {bucket_swaps:<15}")
