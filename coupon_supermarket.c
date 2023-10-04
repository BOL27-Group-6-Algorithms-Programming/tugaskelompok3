#include <stdio.h>

/*
    This is a program to dicount coupun to customers.
    Rules:
        - Minimal Purchase of Rp 100,000.-
        - For each Rp 100,000.-, the customer will get a 5% discount.
    Eg:
        A customer with a total amount of purchases of Rp 250,000.- will get 2 coupons.
        The customer will get Rp 25,000.- discount (10% discount in total)
        and the total that they should pay is Rp 225,000.-
    
*/

const float DISCOUNT_PERCENTAGE_PER_COUPON = 0.05;

int calculateHowManyCouponTheCustomerWillReceive(int purchaseAmount) {
    int minimalAmountToGetCoupon = 100000;
    int numberOfCoupons = purchaseAmount/minimalAmountToGetCoupon;
    return numberOfCoupons;
}

float calculateTotalDiscount(float discountInPercentage, float purchaseAmount) {
    return discountInPercentage*purchaseAmount;
}

int main() {
    int totalCouponCustomerReceived;
    float totalAmountToBePaid, discountAmount, totalDiscountInPercentage, purchaseAmount;

    printf("Total pembelian =  ");
    scanf("%f", &purchaseAmount);

    printf("Total pembelian = %f\n", purchaseAmount);
    totalCouponCustomerReceived = calculateHowManyCouponTheCustomerWillReceive((int)purchaseAmount);
    if (totalCouponCustomerReceived > 0) {
        printf("Selamat anda mendapatkan %d kupon\n", totalCouponCustomerReceived);
        totalDiscountInPercentage = totalCouponCustomerReceived*DISCOUNT_PERCENTAGE_PER_COUPON;
        printf("total discount in percentage = %.2f", totalDiscountInPercentage);

        discountAmount = calculateTotalDiscount(totalDiscountInPercentage, purchaseAmount);
        printf("total pengurangan discount = %.2f\n", discountAmount);
    }

    totalAmountToBePaid = purchaseAmount-discountAmount;
    printf("Total yang harus di bayarkan = %.2f\n", totalAmountToBePaid);

    return 0;
}