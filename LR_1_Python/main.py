from structures import (
    SinglyLinkedList,
    DoublyLinkedList,
    Stack,
    Queue,
    EmptyStructureError,
    IndexError as StructIndexError,
    ValueNotFoundError,
)

def print_separator(title):
    """Вспомогательная функция для красивого вывода."""
    print("\n" + "=" * 60)
    print(f"  {title}")
    print("=" * 60)

def demo_singly_linked_list():
    print_separator("Демонстрация односвязного списка")

    # Создание пустого списка
    lst = SinglyLinkedList()
    print(f"Создан пустой список: {lst}")

    # Добавление элементов
    lst.prepend(1)
    print(f"После prepend(1): {lst}")

    lst.append(2)
    print(f"После append(2): {lst}")

    lst.insert_after(1, 3)
    print(f"После insert_after(1, 3): {lst}")

    lst.insert_before(1, 4)
    print(f"После insert_before(1, 4): {lst}")

    # Поиск
    print("\n--- Поиск элементов ---")
    print(f"find(2) -> {lst.find(2)}")
    print(f"find_all(1) -> {lst.find_all(1)}")
    print(f"contains(5) -> {lst.contains(5)}")
    print(f"5 in lst -> {5 in lst}")

    # Доступ по индексу и изменение
    print(f"\nlst[0] = {lst[0]}")
    lst[0] = 99
    print(f"После lst[0] = 99: {lst}")

    # Удаление
    lst.remove_at(2)
    print(f"После remove_at(2): {lst}")

    lst.remove_value(4)
    print(f"После remove_value(4): {lst}")

    lst.remove_first()
    print(f"После remove_first(): {lst}")

    lst.remove_last()
    print(f"После remove_last(): {lst}")

    # Перегрузка операторов
    lst1 = SinglyLinkedList()
    lst1.append(10)
    lst1.append(20)

    lst2 = SinglyLinkedList()
    lst2.append(30)
    lst2.append(40)

    lst3 = lst1 + lst2
    print(f"\nКонкатенация: {lst1} + {lst2} = {lst3}")

    lst4 = lst1 * 3
    print(f"Повторение: {lst1} * 3 = {lst4}")

    # Итерация
    print("Итерация по списку:", end=" ")
    for val in lst1:
        print(val, end=" ")
    print()

    # Длина
    print(f"Длина списка: {len(lst1)}")

def demo_doubly_linked_list():
    print_separator("Демонстрация двусвязного списка")

    dll = DoublyLinkedList()
    dll.append(1)
    dll.append(2)
    dll.append(3)
    dll.prepend(0)
    print(f"Список: {dll}")

    dll.insert_after(2, 99)
    print(f"После insert_after(2, 99): {dll}")

    dll.insert_before(3, 77)
    print(f"После insert_before(3, 77): {dll}")

    print(f"get(3) -> {dll.get(3)}")
    dll[3] = 88
    print(f"После dll[3] = 88: {dll}")

    dll.remove_at(2)
    print(f"После remove_at(2): {dll}")

    dll.remove_value(88)
    print(f"После remove_value(88): {dll}")

    print(f"find(77) -> {dll.find(77)}")
    print(f"find_all(0) -> {dll.find_all(0)}")

    # Операторы
    dll1 = DoublyLinkedList()
    dll1.append(100)
    dll1.append(200)
    dll2 = DoublyLinkedList()
    dll2.append(300)
    print(f"Сложение: {dll1} + {dll2} = {dll1 + dll2}")
    print(f"Умножение: {dll1} * 2 = {dll1 * 2}")

def demo_stack():
    print_separator("Демонстрация стека (LIFO)")

    stack = Stack()
    print("Добавляем 10, 20, 30")
    stack.push(10)
    stack.push(20)
    stack.push(30)

    print(f"Стек (вершина слева): {stack}")
    print(f"peek() -> {stack.peek()}")
    print(f"pop() -> {stack.pop()}")
    print(f"После pop(), стек: {stack}")
    print(f"size() -> {stack.size()}")
    print(f"is_empty() -> {stack.is_empty()}")

    # Итерация
    print("Итерация по стеку (сверху вниз):", end=" ")
    for val in stack:
        print(val, end=" ")
    print()

    # Преобразование из очереди
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    print(f"\nОчередь: {q}")
    stack_from_q = Stack.from_queue(q)
    print(f"Стек из очереди: {stack_from_q}")
    print(f"Исходная очередь после преобразования (должна быть пустой): {q}")

def demo_queue():
    print_separator("Демонстрация очереди (FIFO)")

    queue = Queue()
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    print(f"Очередь: {queue}")
    print(f"front() -> {queue.front()}")
    print(f"dequeue() -> {queue.dequeue()}")
    print(f"После dequeue, очередь: {queue}")
    print(f"size() -> {queue.size()}")
    print(f"is_empty() -> {queue.is_empty()}")

    # Итерация
    print("Итерация по очереди:", end=" ")
    for val in queue:
        print(val, end=" ")
    print()

    # Преобразование из стека
    s = Stack()
    s.push(10)
    s.push(20)
    s.push(30)
    print(f"\nСтек: {s}")
    queue_from_s = Queue.from_stack(s)
    print(f"Очередь из стека: {queue_from_s}")
    print(f"Исходный стек после преобразования: {s}")

def demo_exceptions():
    print_separator("Демонстрация обработки исключений")

    # 1. Обращение к пустому списку
    try:
        lst = SinglyLinkedList()
        print("Пытаемся получить элемент из пустого списка lst.get(0)")
        elem = lst.get(0)
    except StructIndexError as e:
        print(f"Перехвачено исключение: {e}")

    # 2. Удаление из пустого стека
    try:
        stack = Stack()
        print("Пытаемся выполнить pop() из пустого стека")
        stack.pop()
    except EmptyStructureError as e:
        print(f"Перехвачено исключение: {e}")

    # 3. Удаление несуществующего значения
    try:
        lst = SinglyLinkedList()
        lst.append(42)
        print("Пытаемся удалить значение 100, которого нет в списке")
        lst.remove_value(100)
    except ValueNotFoundError as e:
        print(f"Перехвачено исключение: {e}")

    # 4. Выход за границы индекса
    try:
        lst = SinglyLinkedList()
        lst.append(10)
        lst.append(20)
        print("Пытаемся обратиться по индексу 5")
        print(lst[5])
    except StructIndexError as e:
        print(f"Перехвачено исключение: {e}")

def demo_conversion():
    print_separator("Дополнительно: преобразования между структурами")

    # Очередь -> Стек -> Очередь
    original_queue = Queue()
    for i in range(1, 5):
        original_queue.enqueue(i)
    print(f"Исходная очередь: {original_queue}")

    stack = Stack.from_queue(original_queue)
    print(f"Стек из очереди: {stack}")

    new_queue = Queue.from_stack(stack)
    print(f"Очередь из стека: {new_queue}")

    # Проверка, что элементы не потерялись и порядок корректен
    print(f"Исходная очередь стала пустой: {original_queue.is_empty()}")
    print(f"Стек после преобразования пуст: {stack.is_empty()}")
    print(f"Новая очередь содержит те же элементы (порядок FIFO): {new_queue}")

def main():
    demo_singly_linked_list()
    demo_doubly_linked_list()
    demo_stack()
    demo_queue()
    demo_exceptions()
    demo_conversion()

if __name__ == "__main__":
    main()