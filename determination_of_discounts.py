# determination of discounts
# with if-else

print('determination of discounts')
print('--------------------------')

greatPurchase = int(input('Purchase nominal value = '));

if greatPurchase >= 200000:
  discount = 0.05 * greatPurchase
else:
  duscount = 0
  
bigPayment = greatPurchase - discount

# Show result
print()
print('purchase =', greatPurchase)
print('Discount =', discount)
print('payment =', bigPayment)
