// ПРИМЕР СБРОСА ВСЕХ НАСТРОЕК В ЗАВОДСКИЕ:       // * Строки со звёздочкой являются необязательными.
                                                  //
// TDS/EC-метр с щупом (Trema-модуль) Flash-I2C:  //   https://iarduino.ru/shop/Sensory-Datchiki/bamper-s-9-datchikami-liniy-s-shagom-7mm-flash-i2c.html
// Информация о подключении модулей к шине I2C:   //   https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:     //   https://wiki.iarduino.ru/page/TDS-EC-i2c/
                                                  //
#include <Wire.h>                                 //   Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки iarduino_I2C_TDS.
#include <iarduino_I2C_TDS.h>                     //   Подключаем библиотеку для работы с TDS/EC-метром I2C-flash.
iarduino_I2C_TDS tds(0x09);                       //   Объявляем объект tds  для работы с функциями и методами библиотеки iarduino_I2C_TDS, указывая адрес модуля на шине I2C.
                                                  //   Если объявить объект без указания адреса (iarduino_I2C_TDS tds;), то адрес будет найден автоматически.
void setup(){                                     //
     delay(500);                                  // * Ждём завершение переходных процессов связанных с подачей питания.
     tds.begin(&Wire); // &Wire1, &Wire2 ...      //   Инициируем работу с TDS/EC-метром, указав ссылку на объект для работы с шиной I2C на которой находится модуль (по умолчанию &Wire).
     tds.setPullI2C(true);                        // * Устанавливаем подтяжку линий шины I2C (можно не подтягивать, если шину уже подтягивают другие модули).
     tds.setFrequency(   2000);                   //   Устанавливаем частоту переменного тока используемого для измерений.
     tds.setKnownTDS (1,  500);                   //   Устанавливаем концентрацию 1 раствора для калибровки модуля кнопкой.
     tds.setKnownTDS (2, 1500);                   //   Устанавливаем концентрацию 2 раствора для калибровки модуля кнопкой.
     tds.setKa       ( 1000.0);                   //   Устанавливаем множитель степенной функции.
     tds.setKb       (  5.000);                   //   Устанавливаем степень степенной функции.
}                                                 //
                                                  //
void loop(){}                                     //