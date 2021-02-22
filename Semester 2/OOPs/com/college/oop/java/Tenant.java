package com.college.oop.java;

public class Tenant {
    String IDpenyewa;
    String nama;
    String alamat;
    String KTP;
    String noTelp;
    String jenKendaraan;
    String noPlat;
    int lamaSewa;
    int biayaSewa;
    final byte TUJUH_HARI = 7;
    final byte LIMA_HARI = 5;
    final byte TIGA_HARI = 3;
    final byte DUA_HARI = 2;
    final double LIMA_PERSEN = 0.05D;
    final double TIGA_PERSEN = 0.03D;
    final double DUA_PERSEN = 0.02D;
    
    public double HargaSewa( int m_lamaSewa, int m_biayaSewa ) {

        this.lamaSewa = m_lamaSewa;
        this.biayaSewa = m_biayaSewa;

        return m_lamaSewa * m_biayaSewa;
    }

    public double PotonganHarga( int m_lamaSewa, int m_biayaSewa ) {

        this.lamaSewa = m_lamaSewa;
        this.biayaSewa = m_biayaSewa;

        double totalSewa = HargaSewa( m_lamaSewa, m_biayaSewa );

        if ( m_lamaSewa >= TUJUH_HARI  ) {
            return totalSewa * LIMA_PERSEN;
        }

        else if ( m_lamaSewa >= LIMA_HARI ) {
            return totalSewa * TIGA_PERSEN;
        }

        else if ( m_lamaSewa >= TIGA_HARI ) {
            return totalSewa * DUA_PERSEN;
        }

        else if ( m_lamaSewa <= DUA_HARI ) {
            return totalSewa;
        }

        return totalSewa;
    }

    public double HargaDiskon( int m_lamaSewa, int m_biayaSewa ) {
        
        this.lamaSewa = m_lamaSewa;
        this.biayaSewa = m_biayaSewa;

        return HargaSewa( m_lamaSewa, m_biayaSewa ) - PotonganHarga( m_lamaSewa, m_biayaSewa );
    }

    public double PPN( int m_lamaSewa, int m_biayaSewa ) {

        this.lamaSewa = m_lamaSewa;
        this.biayaSewa = m_biayaSewa;

        final double DUA_PERSEN = 0.02;
        double totalSewa = HargaSewa( m_lamaSewa, m_biayaSewa );

        return totalSewa * DUA_PERSEN;
    }

    public double Bayar( int m_lamaSewa, int m_biayaSewa ) {

        this.lamaSewa = m_lamaSewa;
        this.biayaSewa = m_biayaSewa;

        double totalSewa = HargaSewa( m_lamaSewa, m_biayaSewa );
        double potonganHarga = PotonganHarga( m_lamaSewa, m_biayaSewa );
        double ppn = PPN( m_lamaSewa, m_biayaSewa );

        return totalSewa - potonganHarga + ppn;
    }
}