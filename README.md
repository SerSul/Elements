# Проект "Динамические Элементы"

Этот проект демонстрирует работу с графической библиотекой Raylib для создания интерактивного приложения, в котором элементы притягиваются или отталкиваются от курсора мыши, меняют свою скорость и цвет в зависимости от расстояния до курсора.

### Требования

Для работы с проектом вам понадобится следующее программное обеспечение:

- Компилятор C++, поддерживающий стандарт C++11 и выше (например, GCC, Clang, MSVC)
- [Raylib](https://www.raylib.com/) - графическая библиотека для C и C++
- CMake (опционально) для сборки проекта (если ваш проект настроен на использование CMake)

### Установка

#### Установка Raylib

Прежде всего, необходимо установить библиотеку Raylib. Инструкции по установке для различных операционных систем можно найти в [официальной документации Raylib](https://github.com/raysan5/raylib/wiki).

#### Установка через vcpkg

Если вы используете Windows, библиотеку Raylib можно установить с помощью менеджера пакетов vcpkg, выполнив следующую команду в командной строке:

```bash
vcpkg install raylib:x64-windows
```
Убедитесь, что у вас установлен vcpkg и он корректно настроен для использования в вашей среде разработки.

### Сборка проекта

После установки Raylib вы можете собрать проект. Если вы используете CMake, выполните следующие шаги в терминале:

```bash
mkdir build
cd build
cmake ..
make
```
Если ваш проект не использует CMake, вам нужно будет скомпилировать исходный код вручную или с помощью вашей IDE, убедившись, что пути к библиотекам и заголовочным файлам Raylib корректно указаны.
### Запуск

После сборки запустите исполняемый файл вашего проекта. Если все было сделано правильно, вы увидите окно приложения, в котором элементы взаимодействуют с курсором мыши.

Альтернативно, можно скачать готовую папку ray и запустить ```Elements.exe```, или скомпилировать проект в любой известной IDE, предварительно настроив пути к библиотеке Raylib.
