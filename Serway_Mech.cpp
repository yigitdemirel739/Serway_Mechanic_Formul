#include <iostream>
#include <cmath>

//Constant kısmını buradan degistirebilirsibniz...
//ONEMLI NOT PI DEGERI FARKLIYSA LUTFEN DEGISTIRIN...
//PI YI FARKLI BIR DEGER OLARAK VERMISSE SONUC YANLIS CIKAR...

const double PI = 3.14;
const double Gravity = 9.81;

//SERWAY MECHANIC 1 KITABININ TAMAMININ KONULARI ASAGIDADIR...

void hareketVeDinamik(); //1. Konu
void newtonunHareketYasalari(); //2. Konu
void isEnerjiGuc(); //3. Konu 
void momentumVeCarpisma(); //4. Konu 
void donmeharaketleri(); //5. Konu
void acısalMomentum(); //6. Konu 
void salınımlarDalgaHaraketleri(); //7. Konu
void akıskanlarMekanıgı(); //8. Konu


void hareketVeDinamik(){
    int choice;
    double m, v, a, t, F, d, h, result;

    std::cout << "\n1. Hareketin Tanımı (d = v0 * t + (1/2) * a * t^2)\n";
    std::cout << "2. Kuvvet (F = m * a)\n";
    std::cout << "3. Kinetik Enerji (KE = 1/2 * m * v^2)\n";
    std::cout << "4. Potansiyel Enerji (PE = m * g * h)\n";
    std::cout << "Seçiminizi giriniz: ";
    std::cin >> choice;

    switch (choice) {
        // (V .t) + (0.5.a.t^2) ya da (a.t^2/2) bence ikincisini akılda tutmak daha kolay 
        //EGER SORUDA ILK HIZ YOKSA (V .t) yi SIFIR "0" ALLL!!!!
        case 1:
        std::cout <<" Sabit ivmeli Haraket Formülü:"<< std :: endl;
        
            std::cout << "Başlangıç hızı (m/s): "; std::cin >> v;
            std::cout << "Zaman (s): "; std::cin >> t;
            std::cout << "Açısal ivme (m/s²): "; std::cin >> a;
            result = v * t + 0.5 * a * t * t;
            std::cout << "Hareketin sonucu: " << result << " m\n";
            break;
            // F = m.a NEWTONUN IKINCI YASASI !!!
        case 2:
        std::cout <<"Newtonun Ikinci Yasasının Formulu:"<< std :: endl;
            std::cout << "Kütle (kg): "; std::cin >> m;
            std::cout << "Açısal ivme (m/s²): "; std::cin >> a;
            result = m * a;
            std::cout << "Kuvvet: " << result << " N\n";
            break;
            // KINETIK ENERJI FORMULU M.V^2/2 (kısacası ve bana göre daha kolayı)
        case 3:
        std::cout <<"Kinetik Enerji Formülü:" << std :: endl;
            std::cout << "Hız (m/s): "; std::cin >> v;
            std::cout << "Kütle (kg): "; std::cin >> m;
            result = 0.5 * m * v * v;
            std::cout << "Kinetik Enerji: " << result << " J\n";
            break;
            // Yere dusen cısmın potansiyel enerjisi m.g.h
        case 4:
        std::cout <<"Yercekimi Potansiyel Enerjisi:"<< std :: endl;
            std::cout << "Kütle (kg): "; std::cin >> m;
            std::cout << "Yükseklik (m): "; std::cin >> h;
            result = m * Gravity * h;
            std::cout << "Potansiyel Enerji: " << result << " J\n";
            break;
        default:
            std::cout << "Geçersiz seçim!\n";
    }
}
void newtonunHareketYasalari() {
    int choice;
    double F, m, a, v, t, result;
    
    std::cout << "\n1. Newton'un Birinci Yasası (F = m * a)\n";
    std::cout << "2. Newton'un İkinci Yasası (F = m * a)\n";
    std::cout << "3. Newton'un Üçüncü Yasası (F1 = -F2)\n";
    std::cout << "4. Hareket Denklemi (v = v0 + at)\n";
    std::cout << "Seçiminizi giriniz: ";
    std::cin >> choice;

    switch (choice) {
        // CISME ETKI EDEN VE SABIT KALMASINI SAGLAYAN DIGER KUVVET NEWTONUN 1. YASASIDIR
        // YANI BIR KUTU "10KG" YERDE SABIT KALIYORSA YERIN KUTUYA YAPTIGI KUVVET VE YUKARIDAN YER CEKIMININ YAPTIGI KUVVET ESITTIR
        case 1:
            std::cout << "SAKIN UNUTMA!!! 1. KURAL ILE IKINCI KURAL NEREDEYSE AYNI..."<< std::endl;
            std::cout << "CISIM DURAGAN,SABIT HARAKETLI ISE CISME ETKI EDEN KUVVETLER ESITTIR:"<< std::endl;
        
            std::cout << "Kütle (kg): "; std::cin >> m;
            std::cout << "Açısal ivme (m/s²): "; std::cin >> a;
            result = m * a;
            std::cout << "Kuvvet: " << result << " N\n";
            break;
        case 2:
            std::cout << "Newtonun 2. Yasası:"<< std::endl;
            std::cout << "Kütle (kg): "; std::cin >> m;
            std::cout << "İvme (m/s²): "; std::cin >> a;
            result = m * a;
            std::cout << "Kuvvet: " << result << " N\n";
            break;
        case 3:
            std::cout << "F1: "; std::cin >> F;
            std::cout << "F2: "; std::cin >> F;
            result = -F;
            std::cout << "F2: " << result << " N\n";
            break;
        case 4:
            std::cout << "Başlangıç hızı (m/s): "; std::cin >> v;
            std::cout << "Zaman (s): "; std::cin >> t;
            std::cout << "Açısal ivme (m/s²): "; std::cin >> a;
            result = v + a * t;
            std::cout << "Hız: " << result << " m/s\n";
            break;
        default:
            std::cout << "Geçersiz seçim!\n";
    }
}
// PE potansiyel enerji demek

void isEnerjiGuc() {
    int choice;
    double F, d, t, W, P, E, m, h, g, result;
    std::cout << "\n1. İş (W = F * d)\n";
    std::cout << "2. Güç (P = W / t)\n";
    std::cout << "3. Enerji (E = F * d)\n";
    std::cout << "4. Potansiyel Enerji (PE = m * g * h)\n";
    std::cout << "Seçiminizi giriniz: ";
    std::cin >> choice;

    switch (choice) {

        // F * d = yapılan isin formuludur
    
        case 1:
            std::cout << " EGER SORUDA BIR ACI VERILMISSE COS CISNINDEN SONUCLA CARP"<< std::endl;
            std::cout << "Kuvvet (N): "; std::cin >> F;
            std::cout << "Mesafe (m): "; std::cin >> d;
            result = F * d;
            std::cout << "İş: " << result << " J\n";
            break;
        // W/t = gücün formuludur
        case 2:
            std::cout << "İş (J): "; std::cin >> W;
            std::cout << "Zaman (s): "; std::cin >> t;
            result = W / t;
            std::cout << "Güç: " << result << " W\n";
            break;
        // F * d benzer kavramlardır fakat o ıs ıcın harcanan enerjıyı gosterır.
        case 3:
            std::cout << "Kuvvet (N): "; std::cin >> F;
            std::cout << "Mesafe (m): "; std::cin >> d;
            result = F * d;
            std::cout << "Enerji: " << result << " J\n";
            break;
        // m * g * h yercekımı potansıyel enerjı formuludur
        case 4:
            std::cout << "Kütle (kg): "; std::cin >> m;
            std::cout << "Yerçekimi ivmesi (m/s²): "; std::cin >> g;
            std::cout << "Yükseklik (m): "; std::cin >> h;
            result = m * g * h;
            std::cout << "Potansiyel Enerji: " << result << " J\n";
            break;
        default:
            std::cout << "Geçersiz seçim!\n";
    }
}
void momentumVeCarpisma() {
    int choice;
    double m1, m2, v1, v2, v1_prime, v2_prime, result;
    std::cout << "KE (KINETIK ENERJI)";
    std::cout << "\n1. Momentum Korunumu (m1v1 + m2v2 = m1v1' + m2v2')\n";
    std::cout << "2. Elastik Çarpışma (m1v1 + m2v2 = m1v1' + m2v2' ve KE korunur)\n";
    std::cout << "3. Inelastik Çarpışma (KE kaybı veya azalımı vardır)\n";
    std::cout << "Seçiminizi giriniz: ";
    std::cin >> choice;

    switch (choice) {
        // Carpısmada momentumun korunumu
        // Carpısma oncesı toplam momentum ve carpısma sonrası toplam momentum farkı
        case 1:
            std::cout << "Birinci cisim kütlesi (kg): "; std::cin >> m1;
            std::cout << "İkinci cisim kütlesi (kg): "; std::cin >> m2;
            std::cout << "Birinci cisim hızı (m/s): "; std::cin >> v1;
            std::cout << "İkinci cisim hızı (m/s): "; std::cin >> v2;
            std::cout << "Birinci cisim hızının yeni değeri (m/s): "; std::cin >> v1_prime;
            std::cout << "İkinci cisim hızının yeni değeri (m/s): "; std::cin >> v2_prime;
            result = (m1 * v1 + m2 * v2) - (m1 * v1_prime + m2 * v2_prime);
            std::cout << "Momentum değişimi: " << result << " kg.m/s\n";
            break;
        case 2:
        // Kınetık enerjı degısımı (KAYBI ve KORUNUMU)
            std::cout << "Birinci cisim kütlesi (kg): "; std::cin >> m1;
            std::cout << "İkinci cisim kütlesi (kg): "; std::cin >> m2;
            std::cout << "Birinci cisim hızı (m/s): "; std::cin >> v1;
            std::cout << "İkinci cisim hızı (m/s): "; std::cin >> v2;
            std::cout << "Birinci cisim hızının yeni değeri (m/s): "; std::cin >> v1_prime;
            std::cout << "İkinci cisim hızının yeni değeri (m/s): "; std::cin >> v2_prime;
            result = 0.5 * m1 * (v1 * v1 - v1_prime * v1_prime) + 0.5 * m2 * (v2 * v2 - v2_prime * v2_prime);
            std::cout << "Kinetik enerji kaybı: " << result << " J\n";
            break;
        // Toplam enerjı degisim formulu
        case 3:
            std::cout << "Birinci cisim kütlesi (kg): "; std::cin >> m1;
            std::cout << "İkinci cisim kütlesi (kg): "; std::cin >> m2;
            std::cout << "Birinci cisim hızı (m/s): "; std::cin >> v1;
            std::cout << "İkinci cisim hızı (m/s): "; std::cin >> v2;
            std::cout << "Birinci cisim hızının yeni değeri (m/s): "; std::cin >> v1_prime;
            std::cout << "İkinci cisim hızının yeni değeri (m/s): "; std::cin >> v2_prime;
            result = 0.5 * m1 * (v1 * v1 + v2 * v2) - 0.5 * m1 * (v1_prime * v1_prime + v2_prime * v2_prime);
            std::cout << "Kinetik enerji kaybı (inelastik çarpışma): " << result << " J\n";
            break;
        default:
            std::cout << "Geçersiz seçim!\n";
    }
}
void donmeharaketleri (){
    int choice;
    double m, r, F, theta, v, I, omega, alpha, t, L, Ek, result;

    std::cout << "1. Açısal Hız Hesaplama (angle/t)\n";
    std::cout << "2. Açısal İvme Hesaplama (rad/s - rad/s / t)\n";
    std::cout << "3. Tork Hesaplama (theta = theta * (pi / 180);)\n";
    std::cout << "4. Eylemsizlik Momentini Hesaplama (I = Kg * m^2(I))\n";
    std::cout << "5. Dönme Kinetik Enerjisi (1/2 * m * v^2 (KE))\n";
    std::cout << "6. Açısal Momentum Hesaplama (L)\n";
    std::cout << "Seçiminizi yapınız: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            // Acısal hız hesaplama
            std::cout << "Acısal yer değiştirme (rad): ";
            std::cin >> theta;
            std::cout << "Zaman (saniye): ";
            std::cin >> t;
            omega = theta / t;
            std::cout << "Acısal hız (omega): " << omega << " rad/s\n";
            break;

        case 2:
            // Acısal ivme hesaplama
            std::cout << "Başlangıç açısal hız (omega_i) (rad/s): ";
            std::cin >> omega;
            std::cout << "Son açısal hız (omega_f) (rad/s): ";
            std::cin >> omega;
            std::cout << "Zaman (saniye): ";
            std::cin >> t;
            alpha = (omega - omega) / t;
            std::cout << "Açısal ivme (alpha): " << alpha << " rad/s^2\n";
            break;

        case 3:
            // Tork hesaplama
            std::cout << "Kuvvet (N): ";
            std::cin >> F;
            std::cout << "Kuvvetin uygulandığı mesafe (r) (metre): ";
            std::cin >> r;
            std::cout << "Kuvvetin kol ile yaptığı açı (derece): ";
            std::cin >> theta;
            // Açıyı radiyana çeviriyoruz
            theta = theta * (PI / 180);
            result = r * F * sin(theta);
            std::cout << "Tork (torque): " << result << " N.m\n";
            break;

        case 4:
            // Eylemsizlik momenti hesaplama
            std::cout << "Kütle (kg): ";
            std::cin >> m;
            std::cout << "Yarıçap (m): ";
            std::cin >> r;
            I = 0.5 * m * r * r;  // Düzgün disk için örnek
            std::cout << "Eylemsizlik momenti (I): " << I << " kg.m^2\n";
            break;

        case 5:
            // Donme kinetik enerjisi hesaplama
            std::cout << "Eylemsizlik momenti (I) (kg.m^2): ";
            std::cin >> I;
            std::cout << "Açısal hız (omega) (rad/s): ";
            std::cin >> omega;
            Ek = 0.5 * I * omega * omega;
            std::cout << "Dönme kinetik enerjisi (Ek): " << Ek << " J\n";
            break;

        case 6:
            // Acısal momentum hesaplama
            std::cout << "Eylemsizlik momenti (I) (kg.m^2): ";
            std::cin >> I;
            std::cout << "Açısal hız (omega) (rad/s): ";
            std::cin >> omega;
            L = I * omega;
            std::cout << "Açısal momentum (L): " << L << " kg.m^2/s\n";
            break;

        default:
            std::cout << "Geçersiz seçim!\n";
            break;
    }
}
void acısalMomentum(){

    int choice;
    double L, r, p, I, w, t, dL, dt, Loteleme, Ldonme, m, result;
    while (true) {
        std::cout << "Açısal Momentum Hesap Makinesi\n";
        std::cout << "1. Parcacıgın acısal momentumu (L = r * p * sin(theta))\n";
        std::cout << "2. Dönme Haraketindeki acısal momentum (L = I * w)\n";
        std::cout << "3. Tork ((tau) = dL / dt)\n";
        std::cout << "4. Açısal Momentum Korunumu (I1 * w1 = I2 * w2)\n";
        std::cout << "5. Öteleme ve Dönme Açısal Mom. (L = L_öteleme + L_dönme)\n";
        std::cout << "6. Çıkış\n";
        std::cout << "Seçiminizi yapın: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double theta;
                std::cout << "r (m): "; std::cin >> r;
                std::cout << "m (kg): "; std::cin >> m;
                std::cout << "v (m/s): "; std::cin >> p;
                std::cout << "Theta (derece): "; std::cin >> theta;
                theta = theta * (PI / 180); // Dereceyi radyana çevirme formülü
                L = r * m * p * sin(theta);
                std::cout << "Açısal Momentum: " << L << " kg·m²/s\n";
                break;
            }
            case 2: {
                std::cout << "I (kg·m²): "; std::cin >> I;
                std::cout << "w (rad/s): "; std::cin >> w;
                L = I * w;
                std::cout << "Açısal Momentum: " << L << " kg·m²/s\n";
                break;
            }
            case 3: {
                std::cout << "dL: "; std::cin >> dL;
                std::cout << "dt (s): "; std::cin >> dt;
                result = dL / dt;
                std::cout << "Tork (tau): " << result << " N·m\n";
                break;
            }
            case 4: {
                double I1, w1, I2, w2;
                std::cout << "I1 (kg·m²): "; std::cin >> I1;
                std::cout << "w1 (rad/s): "; std::cin >> w1;
                std::cout << "I2 (kg·m²): "; std::cin >> I2;
                w2 = (I1 * w1) / I2;
                std::cout << "Yeni Açısal Hız (w2): " << w2 << " rad/s\n";
                break;
            }
            case 5: {
                std::cout << "L_öteleme: "; std::cin >> Loteleme;
                std::cout << "L_dönme: "; std::cin >> Ldonme;
                L = Loteleme + Ldonme;
                std::cout << "Toplam Açısal Momentum: " << L << " kg·m²/s\n";
                break;
            }
            case 6:
                std::cout << "Çıkış yapılıyor...\n";
                return;
            default:
                std::cout << "Geçersiz seçim! Tekrar deneyin.\n";
                }
            }
        }
void salınımlarDalgaHaraketleri() {
    int choice; 
    double T, f, w, k, lambda, v, A, m, k_spring, x, E, U, K;
    
    while (true) {
        std::cout << "\nSalınımlar ve Dalga Hareketleri Hesap Makinesi\n";
        std::cout << "1. Periyot (T = 1 / f)\n";
        std::cout << "2. Frekans (f = 1 / T)\n";
        std::cout << "3. Açısal Frekans (w = 2 * PI * f)\n";
        std::cout << "4. Dalga Sayısı (k = 2 * PI / lambda)\n";
        std::cout << "5. Dalga Hızı (v = f * lambda)\n";
        std::cout << "6. Basit Harmonik Hareket Enerjisi (E = 1/2 * k * A^2)\n";
        std::cout << "7. Kinetik Enerji (K = 1/2 * m * v^2)\n";
        std::cout << "8. Potansiyel Enerji (U = 1/2 * k * x^2)\n";
        std::cout << "9. Çıkış\n";
        std::cout << "Seçiminizi yapın: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Frekans (Hz): "; std::cin >> f;
                T = 1 / f;
                std::cout << "Periyot: " << T << " s\n";
                break;
            case 2:
                std::cout << "Periyot (s): "; std::cin >> T;
                f = 1 / T;
                std::cout << "Frekans: " << f << " Hz\n";
                break;
            case 3:
                std::cout << "Frekans (Hz): "; std::cin >> f;
                w = 2 * PI * f;
                std::cout << "Açısal Frekans: " << w << " rad/s\n";
                break;
            case 4:
                std::cout << "Dalga Boyu (m): "; std::cin >> lambda;
                k = 2 * PI / lambda;
                std::cout << "Dalga Sayısı: " << k << " 1/m\n";
                break;
            case 5:
                std::cout << "Frekans (Hz): "; std::cin >> f;
                std::cout << "Dalga Boyu (m): "; std::cin >> lambda;
                v = f * lambda;
                std::cout << "Dalga Hızı: " << v << " m/s\n";
                break;
            case 6:
                std::cout << "Yay Sabiti (N/m): "; std::cin >> k_spring;
                std::cout << "Genlik (m): "; std::cin >> A;
                E = 0.5 * k_spring * A * A;
                std::cout << "Toplam Enerji: " << E << " J\n";
                break;
            case 7:
                std::cout << "Kütle (kg): "; std::cin >> m;
                std::cout << "Hız (m/s): "; std::cin >> v;
                K = 0.5 * m * v * v;
                std::cout << "Kinetik Enerji: " << K << " J\n";
                break;
            case 8:
                std::cout << "Yay Sabiti (N/m): "; std::cin >> k_spring;
                std::cout << "Yer Değiştirme (m): "; std::cin >> x;
                U = 0.5 * k_spring * x * x;
                std::cout << "Potansiyel Enerji: " << U << " J\n";
                break;
            case 9:
                std::cout << "Çıkış yapılıyor...\n";
                return;
            default:
                std::cout << "Geçersiz seçim! Tekrar deneyin.\n";
        }
    }
}
void akıskanlarMekanıgı() {
 int choice; 
 double P, F, A, rho, h, g, Q, v, A1, A2, v1, v2, P1, P2, result;

    while (true) {
        std::cout << "\nAkışkanlar Mekaniği Hesap Makinesi\n";
        std::cout << "1. Basınç (P = F / A)\n";
        std::cout << "2. Hidrostatik Basınç (P = rho * g * h)\n";
        std::cout << "3. Debi (Q = A * v)\n";
        std::cout << "4. Bernoulli Prensibi (P1 + 0.5 * rho * v1^2 + rho * g * h1 = P2 + 0.5 * rho * v2^2 + rho * g * h2)\n";
        std::cout << "5. Çıkış\n";
        std::cout << "Seçiminizi yapın: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Kuvvet (N): "; std::cin >> F;
                std::cout << "Yüzey Alanı (m²): "; std::cin >> A;
                P = F / A;
                std::cout << "Basınç: " << P << " Pa\n";
                break;
            case 2:
                std::cout << "Akışkan Yoğunluğu (kg/m³): "; std::cin >> rho;
                std::cout << "Yerçekimi İvmesi (m/s²): "; std::cin >> g;
                std::cout << "Yükseklik (m): "; std::cin >> h;
                P = rho * g * h;
                std::cout << "Hidrostatik Basınç: " << P << " Pa\n";
                break;
            case 3:
                std::cout << "Kesit Alanı (m²): "; std::cin >> A;
                std::cout << "Akış Hızı (m/s): "; std::cin >> v;
                Q = A * v;
                std::cout << "Debi: " << Q << " m³/s\n";
                break;
            case 4:
                std::cout << "Birinci Nokta Basıncı (Pa): "; std::cin >> P1;
                std::cout << "Birinci Nokta Hızı (m/s): "; std::cin >> v1;
                std::cout << "Birinci Nokta Yüksekliği (m): "; std::cin >> h;
                std::cout << "İkinci Nokta Basıncı (Pa): "; std::cin >> P2;
                std::cout << "İkinci Nokta Hızı (m/s): "; std::cin >> v2;
                std::cout << "İkinci Nokta Yüksekliği (m): "; std::cin >> h;
                result = (P1 + 0.5 * rho * v1 * v1 + rho * g * h) - (P2 + 0.5 * rho * v2 * v2 + rho * g * h);
                std::cout << "Bernoulli Prensibi Sonucu: " << result << " Pa\n";
                break;
            case 5:
                std::cout << "Çıkış yapılıyor...\n";
                return;
            default:
                std::cout << "Geçersiz seçim! Tekrar deneyin.\n";
        }
    }
}
int main() {
    int choice;
    do {
        std::cout << "\n1. Hareket ve Dinamik\n";
        std::cout << "2. Newton'un Hareket Yasaları\n";
        std::cout << "3. İş, Enerji, Güç\n";
        std::cout << "4. Momentum ve Çarpışmalar\n";
        std::cout << "5. Donme Haraketleri\n";
        std::cout << "6. Acısal Momentum\n";
        std::cout << "7. Salınım ve Dalga Haraketleri\n";
        std::cout << "8. Akıskanlar Mekanıgı\n";
        std::cout << "Seçiminizi giriniz (0 çıkış): ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                hareketVeDinamik();
                break;
            case 2:
                newtonunHareketYasalari();
                break;
            case 3:
                isEnerjiGuc();
                break;
            case 4:
                momentumVeCarpisma();
                break;
            case 5:
                donmeharaketleri();
                break;
            case 6:
                acısalMomentum();
                break;
            case 7:
                salınımlarDalgaHaraketleri();
                break;
            case 8:
                akıskanlarMekanıgı();
                break;
            default:
                if (choice != 0) {
                    std::cout << "Geçersiz seçim!\n";
                }
                break;
        }
    } while (choice != 0);

    return 0;
}