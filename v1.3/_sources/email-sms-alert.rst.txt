.. _email-sms-alert:

*******************
Iot Email Sms Alarm
*******************

Alarm nedir?
------------

Iot Kanal altında oluşturulan Elementlere alarm değeri kurma işlemidir. Alarm değeri kurularak iot cihazıdan her veri
alındığında operatör ile işlem yapılarak sonuca göre alarm üretilir. Üretilen alarm abonelik tipine göre bir günde en fazla
atılabilecek email ve sms planına göre belirlenir.

Operatörler
-----------

İşlem operatörleri aşağıdaki gibidir:
    * <   : Küçüktür operatörü. a < b. gelen_deger < alarm_degeri. Iot cihazdan gönderilen değer ile alarm değerini karşılaştırır. İşlem sonucu doğru (True) ise alarm üretilir.
    * <=  : Küçük eşittir operatörü. a <= b. gelen_deger <= alarm_degeri. Iot cihazdan gönderilen değer ile alarm değerini karşılaştırır. İşlem sonucu doğru (True) ise alarm üretilir.
    * ==  : Eşittir operatörü. a == b. gelen_deger == alarm_degeri. Iot cihazdan gönderilen değer ile alarm değerini karşılaştırır. İşlem sonucu doğru (True) ise alarm üretilir.
    * !=  : Eşit değil operatörü. a != b. gelen_deger != alarm_degeri. Iot cihazdan gönderilen değer ile alarm değerini karşılaştırır. İşlem sonucu doğru (True) ise alarm üretilir.
    * >=  : Büyük eşit operatörü. a >= b. gelen_deger >= alarm_degeri. Iot cihazdan gönderilen değer ile alarm değerini karşılaştırır. İşlem sonucu doğru (True) ise alarm üretilir.
    * >   : Büyüktür operatörü. a > b. gelen_deger > alarm_degeri. Iot cihazdan gönderilen değer ile alarm değerini karşılaştırır. İşlem sonucu doğru (True) ise alarm üretilir.

Örnek operatör işlemleri:

    * < Küçüktür operatörü python örnek:
    .. code-block:: python

        a = 5
        b = 7
        a < b
        True

    .. code-block:: python

        a = 9
        b = 7
        a < b
        False

    * <= Küçük eşittir operatörü python örnek :
    .. code-block:: python

        a = 5
        b = 7
        a <= b
        True

    .. code-block:: python

        a = 7
        b = 7
        a <= b
        True

    * == Eşittir operatörü python örnek :
    .. code-block:: python

        a = 5
        b = 7
        a == b
        False

    .. code-block:: python

        a = 7
        b = 7
        a == b
        True

    * != Eşit değil operatörü python örnek :
    .. code-block:: python

        a = 5
        b = 7
        a != b
        True

    .. code-block:: python

        a = 7
        b = 7
        a != b
        False

    * >= Büyük eşit operatörü python örnek :
    .. code-block:: python

        a = 5
        b = 7
        a >= b
        False

    .. code-block:: python

        a = 7
        b = 7
        a >= b
        True

    * > Büyüktür operatörü python örnek :
    .. code-block:: python

        a = 5
        b = 7
        a > b
        False

    .. code-block:: python

        a = 9
        b = 7
        a > b
        True

Email Alarm nedir?
------------------

Iot Kanal/Element alarm işlemi uygulandığında gelen değer ile alarm değeri mantıksal operatör işlem sonucuna göre kanal yöneticisine
email gönderilir. Kayıt olur iken kullanılan email adresi geçerli email adresidir. Günlük (24 saat) email gönderilme sayısı
üyelik planına göre hesaplanır.

SMS Alarm nedir?
----------------

Iot Kanal/Element alarm işlemi uygulandığında gelen değer ile alarm değeri mantıksal operatör işlem sonucuna göre kanal yöneticisine
sms gönderilir. Sms mesaj gönderilebilmesi için kanal yöneticisinin cep telefonunun onaylı olması gerekir. Günlük (24 saat) sms gönderilme sayısı
üyelik planına göre hesaplanır.
