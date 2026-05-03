# PGRubberDucky
Bu araç, Linux (Pardus/ETAP) sistemlerinde OpenSSH sunucusunu otomatik olarak kurmak ve yerel IP adresini merkezi bir sunucuya raporlamak için tasarlanmıştır.

## Dosyalar
* **parsgeeksrubberducky.c**: Programın C kaynak kodu.
* **pgrubberducky.elf**: Derlenmiş, çalıştırılabilir Linux dosyası.

## Gereksinimler
Derleme ve çalıştırma işlemlerinden önce sistemde şu paketlerin kurulu olduğundan emin olun:
```bash
sudo apt update
sudo apt install gcc sshpass -y
```

## Derleme (Compilation)
Kaynak kodunu ELF formatına dönüştürmek için terminale şu komutu yazın:

```bash
gcc parsgeeksrubberducky.c -o pgrubberducky.elf
```

## Çalıştırma (Usage)
1. Oluşturulan dosyaya çalıştırma yetkisi verin:
```bash
chmod +x pgrubberducky.elf
```

2. Programı başlatın:
```bash
./pgrubberducky.elf
```

## Programın İşleyişi
1. `etap+pardus!` şifresini kullanarak arka planda `openssh-server` kurar.
2. `ip a` komutu çıktısını süzerek cihazın yerel IPv4 adresini alır.
3. `192.168.69.31` IP'li merkezi bilgisayara `etapadmin` kullanıcısı ile bağlanır.
4. Karşı bilgisayarda `~/ipmap` klasörü yoksa oluşturur.
5. Gönderen cihazın adını (`hostname`) dosya adı yaparak IP bilgisini bu klasöre kaydeder.

---
*ParsGeeks RubberDucky Project*
