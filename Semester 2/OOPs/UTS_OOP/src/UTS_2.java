public class UTS_2 {
    private double rentFeePerHour;
    private double rentDurationPerHour;

    String code;
    String name;
    String KTP;
    double discount;

    final byte TwelveHours = 12;
    final double TEN_PERCENT = 0.1;

    public double getRentFeePerHour() {
        return this.rentFeePerHour;
    }

    public double getRentDurationPerHour() {
        return this.rentDurationPerHour;
    }

    public void setRentFeePerHour( double rfph_RentFeePerHour ) {
        this.rentFeePerHour = rfph_RentFeePerHour;
    }

    public void setRentDurationPerHour( double rdph_RentDurationPerHour ) {
        this.rentDurationPerHour = rdph_RentDurationPerHour;
    }

    public double rentSubTotal() {
        double subTotal = this.rentFeePerHour * this.rentDurationPerHour;

        return subTotal;
    }

    public double discountTenPercent() {
        return rentSubTotal() * TEN_PERCENT;
    }

    public double noDiscount() {
        discount = 0;

        return discount;
    }

    public double rentDiscount( double disc ) {
        
        double discount = this.discount;
        
        boolean rentDurationMoreThan12Hours = ( this.rentDurationPerHour >= this.TwelveHours );
        boolean rentDurationLessThan12Hours = ( this.rentDurationPerHour < this.TwelveHours );

        if ( rentDurationMoreThan12Hours ) {
            discount = discountTenPercent();
        }

        else if ( rentDurationLessThan12Hours ) {
            discount = noDiscount();
        }

        return discount;
    }

    public double rentTotalPrice() {
        return rentSubTotal() - rentDiscount( this.discount );
    }
}