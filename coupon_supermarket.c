#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

char* formatAsRupiah(float amount) {
    // Convert the float to an integer by rounding to the nearest integer
    long long roundedAmount = (long long)(amount + 0.5);

    // Create a character array to store the formatted string
    char result[30]; // Assuming the maximum length of the result is 30 characters

    // Check if the amount is greater than or equal to one billion
    if (roundedAmount >= 1000000000LL) {
        // Format the rupiah currency string with billion
        snprintf(result, sizeof(result), "Rp %lld.%.3lld.%.3lld.%.3lld,-",
                 roundedAmount / 1000000000LL,
                 (roundedAmount % 1000000000LL) / 1000000LL,
                 (roundedAmount % 1000000LL) / 1000LL,
                 roundedAmount % 1000LL);
    } else {
        // Format the rupiah currency string without billion
        if (roundedAmount >= 1000000LL) {
            // Remove leading zeros in the millions place
            snprintf(result, sizeof(result), "Rp %lld.%.3lld.%.3lld,-",
                     roundedAmount / 1000000LL,
                     (roundedAmount % 1000000LL) / 1000LL,
                     roundedAmount % 1000LL);
        } else {
            // Remove leading zeros in the thousands place
            snprintf(result, sizeof(result), "Rp %lld.%.3lld,-",
                     roundedAmount / 1000LL,
                     roundedAmount % 1000LL);
        }
    }

    // Return the formatted string
    return strdup(result);
}

int main() {
    int totalCouponCustomerReceived;
    float totalAmountToBePaid, discountAmount, discountInDecimal, purchaseAmount;

    printf("Total pembelian = Rp ");
    scanf("%f", &purchaseAmount);

    printf("Total pembelian = %s\n", formatAsRupiah(purchaseAmount));
    totalCouponCustomerReceived = calculateHowManyCouponTheCustomerWillReceive((int)purchaseAmount);
    if (totalCouponCustomerReceived > 0) {
        printf("Selamat anda mendapatkan %d kupon\n", totalCouponCustomerReceived);
        discountInDecimal = totalCouponCustomerReceived*DISCOUNT_PERCENTAGE_PER_COUPON;
        float discountInDecimalTime100 = discountInDecimal*100;
        int discountInPercentage = (int) discountInDecimalTime100;

        printf("total discount in percentage = %d%s\n", discountInPercentage, "%");

        discountAmount = calculateTotalDiscount(discountInDecimal, purchaseAmount);
        printf("total pengurangan discount = %s\n", formatAsRupiah(discountAmount));
    }

    totalAmountToBePaid = purchaseAmount-discountAmount;
    printf("Total yang harus di bayarkan = %s\n", formatAsRupiah(totalAmountToBePaid));

    return 0;
}