// verylong.h
#if !defined(VERYLONGH)
#define VERYLONGH
#include <string>
using namespace std;

/**
 * @class verylong
 * @brief Класс для работы с целыми числами произвольной длины (длинная арифметика).
 * @details Хранит число в виде строки цифр в перевернутом порядке и отдельно знак числа.
 */
class verylong
{
private:
    string number;
    mutable char sign;

public:
    /**
     * @brief Конструктор по умолчанию.
     * @details Создает пустое длинное целое число.
     */
    verylong() {}

    /**
     * @brief Конструктор с одним аргументом.
     * @details Инициализирует объект значением из текстовой строки, содержащей число.
     * @param[in] str Указатель на строку с числом (например, "12345" или "-6789").
     */
    verylong(const char *str);

    /**
     * @brief Дружественный оператор вывода в поток.
     * @details Передает текстовое представление длинного числа с учетом его знака в выходной поток.
     * Перед выводом восстанавливает правильный порядок цифр, если они хранятся реверсивно.
     * @param[in,out] os Ссылка на выходной поток данных (например, std::cout).
     * @param[in] vl Ссылка на константный объект длинного числа для чтения.
     * @return std::ostream& Ссылка на текущий поток вывода для поддержки цепочки вызовов.
     */
    friend ostream &operator<<(ostream &os, const verylong &vl);

    /**
     * @brief Дружественный оператор ввода из потока.
     * @details Считывает строку из потока, корректно выделяет знак числа в sign,
     * очищает строку от нечисловых символов и разворачивает ее для реверсивного хранения.
     * @param[in,out] is Ссылка на входной поток данных (например, std::cin).
     * @param[out] vl Ссылка на модифицируемый объект verylong для записи результата.
     * @return std::istream& Ссылка на текущий поток ввода для поддержки цепочки вызовов.
     */
    friend istream &operator>>(istream &is, verylong &vl);
    /**
     * @brief Оператор явного или неявного приведения к типу int.
     * @details Конвертирует длинное целое число в стандартный тип int.
     * @return int Значение числа в формате стандартного целого.
     */
    operator int() const;

    /**
     * @brief Дружественный оператор сложения двух длинных целых.
     * @details Складывает два объекта verylong поразрядно.
     * @param[in] vl1 Первое слагаемое (длинное целое).
     * @param[in] vl2 Второе слагаемое (длинное целое).
     * @return verylong Новый объект verylong, содержащий результат сложения.
     */
    friend verylong operator+(const verylong &vl1, const verylong &vl2);

    /**
     * @brief Оператор составного присваивания со сложением (verylong).
     * @details Прибавляет к текущему числу другое длинное целое.
     * @param[in] other Второе слагаемое (длинное целое).
     * @return verylong& Ссылка на текущий измененный объект.
     */
    verylong &operator+=(const verylong &other);

    /**
     * @brief Дружественный оператор сложения длинного числа с обычным целым числом.
     * @details Позволяет прибавить к объекту verylong стандартный int.
     * @param[in] vl1 Слагаемое типа verylong (передается по значению).
     * @param[in] d Второе слагаемое типа int.
     * @return verylong Новый объект verylong, содержащий сумму.
     */
    friend verylong operator+(verylong vl1, int d);

    /**
     * @brief Оператор составного присваивания со сложением (verylong).
     * @details Прибавляет к текущему числу другое длинное целое.
     * @param[in] other Второе слагаемое (длинное целое).
     * @return verylong& Ссылка на текущий измененный объект.
     */
    verylong &operator+=(int d);

    /**
     * @brief Дружественный оператор вычитания двух длинных целых.
     * @details Поразрядно вычитает из одного длинного целого другое длинное целое.
     * @param[in] vl1 Уменьшаемое (длинное целое).
     * @param[in] vl2 Вычитаемое (длинное целое).
     * @return verylong Новый объект verylong, содержащий результат вычитания.
     */
    friend verylong operator-(const verylong &vl1, const verylong &vl2);

    /**
     * @brief Оператор составного присваивания с вычитанием (verylong).
     * @details Вычитает из текущего числа другое длинное целое.
     * @param[in] vl Вычитаемое (длинное целое).
     * @return verylong& Ссылка на текущий измененный объект.
     */
    verylong &operator-=(const verylong &vl);

    /**
     * @brief Дружественный оператор вычитания обычного целого числа из длинного числа.
     * @details Позволяет вычесть стандартный int из длинного числа verylong.
     * @param[in] vl1 Уменьшаемое типа verylong.
     * @param[in] d Вычитаемое типа int.
     * @return verylong Новый объект verylong, содержащий результат вычитания.
     */
    friend verylong operator-(verylong vl1, int d);

    /**
     * @brief Оператор составного присваивания с вычитанием (int).
     * @details Вычитает из текущего числа стандартное целое число int.
     * @param[in] d Вычитаемое типа int.
     * @return verylong& Ссылка на текущий измененный объект.
     */
    verylong &operator-=(int d);

    /**
     * @brief Дружественный оператор умножения двух длинных целых.
     * @details Перемножает два длинных числа методом "в столбик".
     * @param[in] vl1 Первый множитель (длинное целое).
     * @param[in] vl2 Второй множитель (длинное целое).
     * @return verylong Новый объект verylong, содержащий результат умножения.
     */
    friend verylong operator*(const verylong &vl1, const verylong &vl2);

    /**
     * @brief Оператор составного присваивания с умножением (verylong).
     * @details Умножает текущее число на другое длинное целое.
     * @param[in] vl Множитель (длинное целое).
     * @return verylong& Ссылка на текущий измененный объект.
     */
    verylong &operator*=(const verylong &vl);

    /**
     * @brief Дружественный оператор деления двух длинных целых.
     * @details Выполняет целочисленное деление двух длинных чисел методом "уголком".
     * @param[in] vl1 Делимое (длинное целое).
     * @param[in] vl2 Делитель (длинное целое).
     * @return verylong Новый объект verylong, содержащий частное.
     */
    friend verylong operator/(const verylong &vl1, const verylong &vl2);

    /**
     * @brief Оператор составного присваивания с делением (verylong).
     * @details Делит текущее число на другое длинное целое.
     * @param[in] vl Делитель (длинное целое).
     * @return verylong& Ссылка на текущий измененный объект.
     */
    verylong &operator/=(const verylong &vl);

    /**
     * @brief Дружественный оператор умножения длинного числа на обычное целое число.
     * @details Перемножает длинное число verylong и стандартный int.
     * @param[in] vl1 Множитель типа verylong.
     * @param[in] d Множитель типа int.
     * @return verylong Новый объект verylong, содержащий результат умножения.
     */
    friend verylong operator*(verylong vl1, int d);

    /**
     * @brief Оператор составного присваивания с умножением (int).
     * @details Умножает текущее число на стандартное целое число int.
     * @param[in] d Множитель типа int.
     * @return verylong& Ссылка на текущий измененный объект.
     */
    verylong &operator*=(int d);

    /**
     * @brief Дружественный оператор деления длинного числа на обычное целое число.
     * @details Выполняет деление длинного числа verylong на стандартный int.
     * @param[in] vl1 Делимое типа verylong.
     * @param[in] d Делитель типа int.
     * @return verylong Новый объект verylong, содержащий частное.
     */
    friend verylong operator/(verylong vl1, int d);

    /**
     * @brief Оператор составного присваивания с делением (int).
     * @details Делит текущее число на стандартное целое число int.
     * @param[in] d Делитель типа int.
     * @return verylong& Ссылка на текущий измененный объект.
     */
    verylong operator/=(int d);

    /**
     * @brief Оператор префиксного инкремента (++vl).
     * @details Увеличивает значение текущего числа на единицу перед использованием.
     * @return verylong& Ссылка на текущий измененный объект.
     */
    verylong &operator++();

    /**
     * @brief Оператор постфиксного инкремента (vl++).
     * @details Увеличивает значение текущего числа на единицу после использования.
     * @param[in] Неиспользуемый параметр int для отличия от префиксной формы.
     * @return verylong Копия объекта до его увеличения.
     */
    verylong operator++(int);

    /**
     * @brief Оператор префиксного декремента (--vl).
     * @details Уменьшает значение текущего числа на единицу перед использованием.
     * @return verylong& Ссылка на текущий измененный объект.
     */
    verylong &operator--();

    /**
     * @brief Оператор постфиксного декремента (vl--).
     * @details Уменьшает значение текущего числа на единицу после использования.
     * @param[in] Неиспользуемый параметр int для отличия от префиксной формы.
     * @return verylong Копия объекта до его уменьшения.
     */
    verylong operator--(int);

    /**
     * @brief Оператор отношения "больше" (verylong).
     * @details Сравнивает текущее длинное число с другим длинным числом.
     * @param[in] vl Правый операнд сравнения (verylong).
     * @return true Если текущее число больше vl.
     * @return false В противном случае.
     */
    bool operator>(const verylong &vl) const;

    /**
     * @brief Оператор отношения "больше или равно" (verylong).
     * @details Сравнивает текущее длинное число с другим длинным числом.
     * @param[in] vl Правый операнд сравнения (verylong).
     * @return true Если текущее число больше или равно vl.
     * @return false В противном случае.
     */
    bool operator>=(const verylong &vl) const;

    /**
     * @brief Оператор отношения "меньше или равно" (verylong).
     * @details Сравнивает текущее длинное число с другим длинным числом.
     * @param[in] vl Правый операнд сравнения (verylong).
     * @return true Если текущее число меньше или равно vl.
     * @return false В противном случае.
     */
    bool operator<(const verylong &vl) const;

    /**
     * @brief Дружественный оператор отношения "больше" (с int).
     * @details Сравнивает длинное число со стандартным целым числом int.
     * @param[in] vl Левый операнд сравнения (verylong).
     * @param[in] d Правый операнд сравнения (int).
     * @return true Если vl больше d.
     * @return false В противном случае.
     */
    bool operator<=(const verylong &vl) const;

    /**
     * @brief Дружественный оператор отношения "больше" (с int).
     * @details Сравнивает длинное число со стандартным целым числом int.
     * @param[in] vl Левый операнд сравнения (verylong).
     * @param[in] d Правый операнд сравнения (int).
     * @return true Если vl больше d.
     * @return false В противном случае.
     */
    friend bool operator>(const verylong &vl, int d);

    /**
     * @brief Дружественный оператор отношения "больше или равно" (с int).
     * @details Сравнивает длинное число со стандартным целым числом int.
     * @param[in] vl Левый операнд сравнения (verylong).
     * @param[in] d Правый операнд сравнения (int).
     * @return true Если vl больше или равно d.
     * @return false В противном случае.
     */
    friend bool operator>=(const verylong &vl, int d);

    /**
     * @brief Дружественный оператор отношения "меньше" (с int).
     * @details Сравнивает длинное число со стандартным целым числом int.
     * @param[in] vl Левый операнд сравнения (verylong).
     * @param[in] d Правый операнд сравнения (int).
     * @return true Если vl меньше d.
     * @return false В противном случае.
     */
    friend bool operator<(const verylong &vl, int d);

    /**
     * @brief Дружественный оператор отношения "меньше или равно" (с int).
     * @details Сравнивает длинное число со стандартным целым числом int.
     * @param[in] vl Левый операнд сравнения (verylong).
     * @param[in] d Правый операнд сравнения (int).
     * @return true Если vl меньше или равно d.
     * @return false В противном случае.
     */
    friend bool operator<=(const verylong &vl, int d);

    /**
     * @brief Оператор проверки равенства двух длинных чисел.
     * @details Сравнивает текущее длинное число с переданным объектом verylong.
     * @param[in] other Правое число для сравнения.
     * @return true Если числа абсолютно одинаковы (совпадают знаки и все цифры).
     * @return false Если числа отличаются.
     */

    bool operator==(const verylong &other) const;

    /**
     * @brief Дружественный оператор проверки равенства длинного числа с обычным целым числом.
     * @details Позволяет быстро сравнить длинное число со стандартным int (например, vl == 0).
     * @param[in] vl Ссылка на константный объект длинного числа (левый операнд).
     * @param[in] d Число типа int для сравнения (правый операнд).
     * @return true Если значения равны.
     * @return false Если значения не равны.
     */
    friend bool operator==(const verylong &vl, int d);

    /**
     * @brief Оператор проверки неравенства двух длинных чисел.
     * @details Проверяет, отличаются ли текущее и переданное длинные числа.
     * @param[in] other Правое длинное целое для сравнения.
     * @return true Если числа не равны.
     * @return false Если числа идентичны.
     */
    bool operator!=(const verylong &other) const;

    /**
     * @brief Дружественный оператор проверки неравенства длинного числа с обычным целым числом.
     * @details Позволяет быстро проверить, не равно ли длинное число значению int (например, vl != -1).
     * @param[in] vl Ссылка на константный объект длинного числа (левый операнд).
     * @param[in] d Число типа int для сравнения (правый операнд).
     * @return true Если значения не равны.
     * @return false Если значения равны.
     */
    friend bool operator!=(const verylong &vl, int d);
};
#endif
