# Задача 1

**Даны файл с населением стран мира за 1960–2018 годы и файл с регионом и группой дохода каждой страны. Опишите структуры и классы для этих данных, прочитайте данные из файлов, вычислите население мира и регионов по годам и запишите результаты в файлы.**

### Данные

Файлы лежат в папке `data/` задачи (данные Всемирного банка: https://data.worldbank.org/indicator/SP.POP.TOTL). Разделитель полей — `;`, первая строка — заголовок.

`world_population_1960-2018.csv` — 217 стран: название, код страны и население за каждый год с 1960 по 2018:

```
Country Name;Country Code;1960;1961;1962;…;2018
Afghanistan;AFG;8996973;9169410;9351441;…;37172386
…
West Bank and Gaza;PSE;;;;…;;1978248;2068845;…;4569087
```

Некоторые страны образовались позже или данные о них неполные: пустое поле — нет данных за этот год. Пропуски есть у пяти стран: Eritrea, Kuwait, Serbia, Sint Maarten (Dutch part), West Bank and Gaza.

`countries.csv` — для тех же 217 стран код, регион, группа дохода и название:

```
Country Code;Region;IncomeGroup;Country Name
AFG;South Asia;Low income;Afghanistan
ALB;Europe & Central Asia;Upper middle income;Albania
DZA;Middle East & North Africa;Upper middle income;Algeria
```

Население мира уже в 1960 году — около 3 миллиардов, больше наибольшего значения `int` (2 147 483 647): для населения используйте `long long`.

### Часть 1. Население мира

1. Чтение файла — класс `FileReader`: функция `read` читает файл в коллекцию строк `std::vector<std::string>`. Строки разбирают отдельные функции. Функция `split` делит строку на поля по разделителю и сохраняет пустые поля: `"a;;b;"` → `{"a", "", "b", ""}`.
2. Структура `Country` с полями `name`, `code` и `std::map<int, long long> yearPopulation` (год → население; лет без данных в `map` нет).
   - Функция-член `std::string toString() const` переводит страну в строку вида
     `Afghanistan (AFG): 8996973[1960], 9169410[1961], 9351441[1962]`. Числа в строки переводите функцией `std::to_string`.
   - Перегрузите `operator<<` для `Country`: он выводит страну в том же виде.
   - Функции `parseYears` (годы из заголовка), `parseCountry` (страна из строки файла), `parseCountries` (все страны из строк файла).
3. Структура `WorldPopulation` с полями `std::vector<Country> countries` и `std::map<int, long long> yearPopulation`. Функции-члены:
   - `readCountryPopulationFromFile(file)` — чтение стран из файла: `FileReader::read`, затем `parseCountries`;
   - `calcWorldPopulation()` — население мира по годам: для каждого года сумма по странам, у которых есть данные за этот год;
   - `writeWorldPopulationToFile(file)` — запись населения мира по годам в файл, две строки — годы и население:

     ```
     1960;1961;1962;…;2018
     3014710265;3055350225;…;7567243296
     ```

Проверьте результат в Excel: откройте `world_population_1960-2018.csv` и сложите столбцы годов. Население мира в 2018 году — 7 567 243 296.

### Часть 2. Регионы и группы дохода

1. Перечисление `enum class IncomeGroup { HIGH, UPPER_MIDDLE, LOWER_MIDDLE, LOW }` — группы дохода `High income`, `Upper middle income`, `Lower middle income`, `Low income`. Функции `parseIncomeGroup` (название группы → значение перечисления) и `toString` (значение → название).
2. Класс `CountryFeature` с закрытыми полями `code_`, `region_` и `IncomeGroup incomeGroup_`, конструктором и функциями `getCode()`, `getRegion()`, `getIncomeGroup()`.
   - Перегрузите `operator<<` для `CountryFeature`: `AFG: South Asia, Low income`.
   - Функции `parseCountryFeature` (характеристики страны из строки файла), `parseCountryFeatures` (из всех строк файла) и `readCountryFeatureFromFile(file)` — чтение из файла в `std::vector<CountryFeature>`.
3. Класс `WorldCountry` с закрытыми полями `name_`, `CountryFeature feature_`, `std::map<int, long long> yearPopulation_`. Функция `makeWorldCountries` объединяет коллекции `Country` и `CountryFeature` в коллекцию `WorldCountry` по коду страны.
4. Класс `WorldRegionPopulation` с закрытыми полями `region_` и `std::map<int, long long> yearPopulation_`. Функция-член `calcWorldRegionPopulation(countries)` вычисляет население своего региона по годам по коллекции `WorldCountry`.
5. Класс `Program` хранит коллекции `CountryFeature`, `WorldCountry` и `WorldRegionPopulation`. Функции-члены:
   - `readCountryPopulationFromFile(populationFile, featuresFile)` — чтение обоих файлов и создание коллекции `WorldCountry`;
   - `findCountriesByIncome(incomeGroup)` — страны с заданной группой дохода;
   - `findUniqueRegion()` — регионы, каждый один раз, по алфавиту;
   - `findCountriesByRegion(region)` — названия стран заданного региона;
   - `calcRegionPopulations()` — население каждого региона по годам (по объекту `WorldRegionPopulation` на регион);
   - `writeWorldRegionPopulationToFile(file)` — запись населения регионов по годам в файл:

     ```
     Region;1960;1961;…;2018
     East Asia & Pacific;1030256390;1033472284;…;2304646596
     Europe & Central Asia;660645650;…;918793590
     …
     ```

   Функция `main` программы вызывает статическую функцию-член `Program::main()`, в ней и выполняется вся работа программы.

Проверьте результат в Excel: откройте `countries.csv` и `world_population_1960-2018.csv` и сложите население стран каждого региона. Сумма населения всех регионов за год равна населению мира.

### Этапы разработки и коммиты

Выполняйте задачу по этапам, по порядку. Этап закончен, когда проходят его открытые тесты, а `Program::main` дополнен выводом результатов этапа. **После каждого этапа сделайте коммит**: один этап — один коммит, сообщение — по образцу из таблицы (`NN` — номер лабораторной). При проверке смотрят историю коммитов: по ней должно быть видно, как шла разработка.

| Этап | Что сделать | Тесты этапа | Сообщение коммита |
|---|---|---|---|
| 1 | `FileReader::read`, `split` | `ctest --preset debug -R "FileReaderTest"` | `feat(lab-NN): реализовать чтение файла и разбиение строки` |
| 2 | `Country`: `toString`, `operator<<`, `parseYears`, `parseCountry`, `parseCountries`; в `main` — вывод нескольких стран | `ctest --preset debug -R "\.CountryTest\."` | `feat(lab-NN): реализовать структуру Country` |
| 3 | `WorldPopulation`; в `main` — запись `world_population.csv` (конец части 1) | `ctest --preset debug -R "WorldPopulationTest"` | `feat(lab-NN): вычислить население мира по годам` |
| 4 | `IncomeGroup`, `CountryFeature`, `operator<<`, чтение `countries.csv` | `ctest --preset debug -R "CountryFeatureTest"` | `feat(lab-NN): реализовать класс CountryFeature` |
| 5 | `WorldCountry`, `makeWorldCountries`, `Program::readCountryPopulationFromFile` | `ctest --preset debug -R "WorldCountryTest\|ProgramTest\.Read"` | `feat(lab-NN): объединить страны с характеристиками` |
| 6 | `findCountriesByIncome`, `findUniqueRegion`, `findCountriesByRegion`; в `main` — вывод выборок | `ctest --preset debug -R "ProgramTest\.Find"` | `feat(lab-NN): реализовать выборки стран` |
| 7 | `WorldRegionPopulation`, `calcRegionPopulations`, `writeWorldRegionPopulationToFile`; в `main` — запись `region_population.csv` | `ctest --preset debug -R "WorldRegionPopulationTest\|ProgramTest\.(Calc\|Write)"` | `feat(lab-NN): вычислить население регионов по годам` |

Свои тесты (`tests/student/`) добавляйте в коммит того этапа, к которому они относятся.

### Файлы программы

Программа собирается в отдельную папку `build/<пресет>/bin/<задача>/`, при сборке туда же копируется папка `data/` задачи. Файлы данных программа находит рядом с собой функцией `cpplabs::dataDirectory()` из `<cpplabs/paths.hpp>`, поэтому её можно запускать из любой текущей папки. Результаты программа записывает туда же, в `data/`: `world_population.csv` (часть 1) и `region_population.csv` (часть 2). Эти файлы в git не добавляются (`data/.gitignore`): программа создаёт их заново при каждом запуске.

### Файлы решения

| Файл | Что в нём |
|---|---|
| `file_reader.hpp/.cpp` | класс `FileReader`, функция `split` |
| `country.hpp/.cpp` | структура `Country`, разбор строк файла населения |
| `world_population.hpp/.cpp` | структура `WorldPopulation` |
| `country_feature.hpp/.cpp` | перечисление `IncomeGroup`, класс `CountryFeature`, разбор строк файла `countries.csv` |
| `world_country.hpp/.cpp` | класс `WorldCountry`, функция `makeWorldCountries` |
| `world_region_population.hpp/.cpp` | класс `WorldRegionPopulation` |
| `program.hpp/.cpp` | класс `Program`, работа программы — `Program::main` |
| `country_populations_main.cpp` | функция `main`: вызывает `Program::main()` |

## Файлы задачи

| Файл | Что в нём |
|---|---|
| `include/country.hpp` | объявления функций — не изменяйте |
| `include/country_feature.hpp` | объявления функций — не изменяйте |
| `include/file_reader.hpp` | объявления функций — не изменяйте |
| `include/program.hpp` | объявления функций — не изменяйте |
| `include/world_country.hpp` | объявления функций — не изменяйте |
| `include/world_population.hpp` | объявления функций — не изменяйте |
| `include/world_region_population.hpp` | объявления функций — не изменяйте |
| `src/country.cpp` | решение: тела функций |
| `src/country_feature.cpp` | решение: тела функций |
| `src/country_populations_main.cpp` | программа: ввод данных, вызов функций, вывод |
| `src/file_reader.cpp` | решение: тела функций |
| `src/program.cpp` | решение: тела функций |
| `src/world_country.cpp` | решение: тела функций |
| `src/world_population.cpp` | решение: тела функций |
| `src/world_region_population.cpp` | решение: тела функций |
| `tests/open/country_feature_test.cpp` | открытые тесты — не изменяйте |
| `tests/open/country_test.cpp` | открытые тесты — не изменяйте |
| `tests/open/file_reader_test.cpp` | открытые тесты — не изменяйте |
| `tests/open/program_test.cpp` | открытые тесты — не изменяйте |
| `tests/open/world_country_test.cpp` | открытые тесты — не изменяйте |
| `tests/open/world_population_test.cpp` | открытые тесты — не изменяйте |
| `tests/open/world_region_population_test.cpp` | открытые тесты — не изменяйте |
| `tests/student/country_populations_test.cpp` | ваши тесты: добавляйте сюда |

Программа собирается в цель `lab-07-task-01_country-populations`. Тесты задачи (открытые и ваши): `ctest --preset debug -R "lab-07-task-01\."`, только ваши: `ctest --preset debug -R "lab-07-task-01\.student\."`.
