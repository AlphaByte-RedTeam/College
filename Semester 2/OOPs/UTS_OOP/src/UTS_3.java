public class UTS_3 {
    double price;
    double quantity;
    double shippingCost;
    double discount;
    final double TEN_PERCENT = 0.1;

    String invoiceNumber;
    String name;
    String code;
    String user;

    public double cost( double shippingCost ) {
        double count = shippingCost * TEN_PERCENT;

        return count;
    }

    public double cost( double itemPrice, double quantity ) {
        double count = itemPrice * quantity;

        return count;
    }

    public double cost( double itemPrice, double quantity, double shippingCost ) {
        double count = cost( itemPrice, quantity ) - cost( shippingCost );

        return count;
    }

    public double discountTenPercent() {
        double disc = cost( this.discount );

        return disc;
    }

    public double noDiscount() {
        double discount = 0;

        return discount;
    }

    public void notValid() {
        System.out.println( "Input tidak valid" );
    }

    public double discountShippingCost( double disc ) {
        this.discount = disc;

        boolean yes = ( user.equals( "Y" )  || user.equals( "y" ) );
        boolean no = ( user.equals( "T" ) || user.equals( "t" ) );
        
        if ( yes ) {
            discountTenPercent();
        }

        else if ( no ) {
            noDiscount();
        }

        else {
            notValid();
        }

        return disc;
    }

    
}