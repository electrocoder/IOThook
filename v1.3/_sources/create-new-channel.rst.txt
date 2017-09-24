.. _create-new-channel:

********
Kanal Aç
********

Iothook kanal; internete bağlı nesneler arasında veri iletimini sağlamak için oluşturulmuş
kanca sistemidir. Kanal ile iot sistemleri veri paylaşımı yapılabilir, veri gönderim işlemleri tanımlanır.

Iothook web servislerini kullanabilmek için üye olunmalıdır. Üyelik
seçenekleri ‘Free’, ‘Student’, ‘Pro’ ve ‘Ultra’ olmak üzere 4
kullanım planı vardır. Üye olmak için adrese gidiniz.

Üyelik adımından sonra yönetim paneli aracılığı ile ‘Kanal Ekle’ ekranına girilir.

Kanal Ekle
----------

Kanal ekleme adımları şu şekildedir:

    * Form Metod: Http (Hyper Text Transfer Protocol) de veriler TCP/IP metodu ile iletilmektedir. Http protokolü üzerinden veri iletimi request ve response istekleri ile gerçekleşir. ‘Request’ gerçekleşmesi istenen     talep, ‘Response’ ise yanıt olarak kullanılır. HTTP protokolüne göre POST, GET veya POST/GET metodu seçilir. Iothook iletişiminde post ve get metodları kullanılmaktadır.
        * Post: Verilerin iot cihazda mesaj gövdesine yerleştirilerek gönderilme işlemidir.
        * Get: Verilerin iot cihaz ile sorgulanma ve cevap alınma talebidir.
        * Post/Get: Veri aktarımının iot nesnesi ile server arasında çift taraflı olacağını gösterir.
    * Form enctype: "application/x-www-form-urlencoded" ile iot cihazından gönderilen karakterlerin gönderilmeden önce kodlanacağını belirtir. "mutlipart/form-data" ise verilerin içerisinde ASCII olmayan verilerin olduğunu dosya veya image formatında veri olduğunu belirtir.
    * Aygıt türü: Iot cihazın türünü belirler. Arduino, Raspberry Pi... gibi
    * Kanal adı: Verilerin toplanacağı kanalın adı.
    * Web site: Veriler bir web sitesinde kullanılacak ise web site adresi girilmelidir.
    * Email ile haber ver: Veri alındığında kayıtlı olan mail adresine mesaj gonderir. Aktif edilirse 15dk. da bir veri gönderilmesi gerekir.
    * Verileri kaydet: Iot nesnesinden gelen verilerin iothook veritabanında saklanması için gereklidir.
    * Resim: Kanal tanıtım resmi olarak kullanılır.
    * Açıklama: Kanal bilgileri girilmelidir.
    * Is public POST: Bu kanal genel kullanıma açık ve veri eklenmesine açıktır.
    * Is public GET: Bu kanal genel kullanıma açık ve verilerin okunmasına izin verir.
    * Yayındamı: Kanalı aktif et.

Element Ekle
------------

Iot cihazınız için kanal oluşturduktan sonra kanalda bulunmasını istediğiniz
veri alanlarını oluşturmalısınız. Bu alanlar veri almaya başlamak
için eklenir. Element verilerine POST veta GET metodu ile ulaşabilirsiniz.

Element ayarları:
-----------------

    * Kanal adı: Elementin hangi kanala veri aktaracağı seçilir.
    * Grafik türü: Toplanan verilerin çizileceği grafik türünü belirler.
    * Element tipi: Verilerin depolanacağı alan tipini belirler. Grafik çizimi sadece "number" veri tipinde yapılmalıdır.
    * Kanal adı: Verilerin toplanacağı kanalın adı.
    * Element adı: Verilerin tutulacağı element adı.
    * Yayındamı: Elementi aktif et.
