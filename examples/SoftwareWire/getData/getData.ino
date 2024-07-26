// ПРИМЕР ПОЛУЧЕНИЯ ДАННЫХ ПО ШИНЕ I2C:                      // * Строки со звёздочкой являются необязательными.
// Требуется установить библиотеку <iarduino_I2C_Software.h> //   https://iarduino.ru/file/627.html
                                                             //
// TDS/EC-метр с щупом (Trema-модуль) Flash-I2C:             //   https://iarduino.ru/shop/Sensory-Datchiki/bamper-s-9-datchikami-liniy-s-shagom-7mm-flash-i2c.html
// Информация о подключении модулей к шине I2C:              //   https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                //   https://wiki.iarduino.ru/page/TDS-EC-i2c/
                                                             //
#include <iarduino_I2C_Software.h>                           //   Подключаем библиотеку для работы с программной шиной I2C, до подключения библиотеки iarduino_I2C_TDS.
SoftTwoWire sWire(3,4);                                      //   Создаём объект программной шины I2C указав выводы которым будет назначена роль линий: SDA, SCL.
                                                             //
#include <iarduino_I2C_TDS.h>                                //   Подключаем библиотеку для работы с TDS/EC-метром I2C-flash.
iarduino_I2C_TDS tds(0x09);                                  //   Объявляем объект tds  для работы с функциями и методами библиотеки iarduino_I2C_TDS, указывая адрес модуля на шине I2C.
                                                             //   Если объявить объект без указания адреса (iarduino_I2C_TDS tds;), то адрес будет найден автоматически.
void setup(){                                                //
     delay(500);                                             // * Ждём завершение переходных процессов связанных с подачей питания.
     Serial.begin(9600);                                     //   Инициируем работу с шиной UART для передачи данных в монитор последовательного порта на скорости 9600 бит/сек.
     tds.begin(&sWire);                                      //   Инициируем работу с TDS/EC-метром, указав ссылку на объект для работы с шиной I2C на которой находится модуль (по умолчанию &Wire).
}                                                            //
                                                             //
void loop(){                                                 //
     tds.set_t(25.00f);                                      //   Указываем текущую температуру жидкости.
     Serial.print("Ro="          );                          //
     Serial.print(tds.getRo()    );                          //   Выводим общее измеренное сопротивление.
     Serial.print("Ом, S="       );                          //
     Serial.print(tds.get_S()    );                          //   Выводим измеренную удельную электропроводность жидкости.
     Serial.print("мСм/см, EC="  );                          //
     Serial.print(tds.getEC()    );                          //   Выводим удельную электропроводность жидкости приведённую к опорной температуре.
     Serial.print("мСм/см, TDS=" );                          //
     Serial.print(tds.getTDS()   );                          //   Выводим количество растворённых твёрдых веществ в жидкости.
     Serial.print(" мг/л\r\n"    );                          //
     delay(1000);                                            //
}                                                            //