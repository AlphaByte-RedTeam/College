import javax.swing.JDialog;
import javax.swing.JOptionPane;

public class UTS3_Main {
    static void makeLine( int length ) {
        for ( int i = 0; i < length; i++ ) {
            System.out.print( "=" );
        }
        System.out.println();
    }
    public static void main(String[] args) {
        UTS_3 item = new UTS_3();
        UTS_3 prices = new UTS_3();
        final JDialog dialog = new JDialog();
        dialog.setAlwaysOnTop( true );

        byte length = 45;
        int askUser;
        
        do {
            item.invoiceNumber = JOptionPane.showInputDialog( "Masukkan Nomor Faktur" );
            item.code = JOptionPane.showInputDialog( "Masukkan Kode Barang" );
            item.name = JOptionPane.showInputDialog( "Masukkan Nama Barang" );
            item.price = Double.parseDouble( JOptionPane.showInputDialog("Masukkan Harga Barang") );
            item.quantity = Double.parseDouble( JOptionPane.showInputDialog("Masukkan Kuantitas Barang") );
            item.shippingCost = Double.parseDouble( JOptionPane.showInputDialog( "Masukkan Biaya Kirim" ) );
            
            askUser = JOptionPane.showConfirmDialog( dialog, "Apakah mendapat diskon?", "Ask User", JOptionPane.YES_NO_OPTION );

            boolean yes = ( askUser == JOptionPane.YES_OPTION );
            boolean no = ( askUser == JOptionPane.NO_OPTION );

            if ( yes ) {

                double discountShippingCost = prices.cost(item.shippingCost);
                double totalCost = prices.cost(item.price, item.quantity, item.shippingCost);

                JOptionPane.showMessageDialog (
                    null,
                    "Selamat anda mendapat diskon 10% biaya kirim" +
                    "\nNomor Faktur:  " + item.invoiceNumber +
                    "\nKode Barang:   " + item.code +
                    "\nNama Barang:   " + item.name +
                    "\nHarga Barang:  " + item.price +
                    "\nKuantitas:     " + String.format("%.0f", item.quantity) +
                    "\nBiaya Kirim:   " + item.shippingCost +
                    "\nDiskon Biaya Kirim: " + discountShippingCost +
                    "\nTotal Biaya Kirim: " + ( totalCost - discountShippingCost )
                );
            }

            else if ( no ) {
                makeLine( length );

                double discountShippingCost = prices.cost(item.shippingCost);
                double totalCost = prices.cost(item.price, item.quantity, item.shippingCost);

                JOptionPane.showMessageDialog (
                    null,
                    "Nomor Faktur:  " + item.invoiceNumber +
                    "\nKode Barang:   " + item.code +
                    "\nNama Barang:   " + item.name +
                    "\nHarga Barang:  " + item.price +
                    "\nKuantitas:     " + String.format("%.0f", item.quantity) +
                    "\nBiaya Kirim:   " + item.shippingCost +
                    "\nDiskon Biaya Kirim: " + discountShippingCost +
                    "\nTotal Biaya Kirim: " + totalCost
                );
            }
            askUser = JOptionPane.showConfirmDialog( dialog, "Apakah anda mau mengulang kembali?", "Ask User", JOptionPane.YES_NO_OPTION );
            
        } while ( askUser == JOptionPane.YES_OPTION );
    }
}