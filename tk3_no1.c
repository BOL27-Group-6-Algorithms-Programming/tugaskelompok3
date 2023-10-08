/*

Pada sebuah super market membuat program hadiah dengan memberikan kupon undian kepada pembeli.
Kupon undian akan diberikan jika total pembelian minimal Rp. 100.000,00 dan dan akan dihitung kelipatannya. Diskon 5% jika tota pembelian minimal Rp. 100.000,00.
Misal : seorang pembeli dengan total pembelian Rp. 250.000,00 maka dapat kupon undian sebanyak 2 lembar. Dan dapat diskon sebesar Rp. 25.000,00,
maka yang dibayar sebesar Rp. 225.000,00.

Revisi: Diskon fix 10%

*/

/*
  I created the program based on revision during class with Pak Tri
*/

#include <stdio.h>

const float discount = 0.10;

/* This is a function to determine how many coupons the user will get */
int countTotalReceivedCoupon(int amount)
{
  int minimalPurchase = 100000;
  int totalCoupon = amount / minimalPurchase;
  return totalCoupon;
}

/* This is a function to count how many discount the user will get */
float countTotalDiscount(float discount, float totalPrice)
{
  return discount * totalPrice;
}

int main()
{

  int totalCoupon;
  float purchaseAmount, totalDiscount, totalAmount;

  printf("==================KASIR==================\n\n");
  printf("Masukkan nilai total belanja:");
  scanf("%f", &purchaseAmount);

  totalCoupon = countTotalReceivedCoupon(purchaseAmount);

  if (totalCoupon > 0)
  {
    printf("\nSelamat anda berhak mendapat %d kupon", totalCoupon);
  } else {
    printf("\nMaaf anda belum berhak mendapatkan kupon");
  }

  if (purchaseAmount >= 100000)
  {
    totalDiscount = countTotalDiscount(discount, purchaseAmount);
    printf("\nAnda berhak mendapat potongan harga sebanyak Rp.%.2f", totalDiscount);
  }
  else
  {
    printf("\nMaaf anda belum berhak mendapatkan potongan harga");
  }

  totalAmount = purchaseAmount - totalDiscount;
  printf("\nTotal harga yang harus dibayarkan Rp.%.2f", totalAmount);
  printf("\n\n=========================================");
  return 0;
}