### Детальні пояснення:
- Зменшення кількості зсувів: Ми зменшуємо кількість зсувів за допомогою операції залишку (%). Це дає змогу уникнути зайвих циклів і оптимізувати обробку.

- Напрямок зсуву: Якщо зсув у протилежний напрямок, ми перетворюємо його на еквівалентний у заданий напрямок.

- Тимчасовий масив для рядка: Для зсуву рядків кожен рядок копіюється у тимчасовий масив, зсувається, а потім переноситься назад у матрицю.

- Тимчасова матриця для стовпців: Для зсуву стовпців створюється нова матриця (допоміжний масив), де зберігається результат зсуву. Після заповнення зсунутими значеннями дані копіюються назад.

- Звільнення пам'яті: У кінці програми виділена пам'ять для основної матриці та тимчасових структур звільняється, щоб уникнути витоків пам'яті.