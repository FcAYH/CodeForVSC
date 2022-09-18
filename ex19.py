def cheese_and_crackers(cheese_count, boxes_of_crackers):
    print(f"You have {cheese_count} cheeses!")
    print(f"You have {boxes_of_crackers} boxes_of_crackers!")
    print("Man that's enough for a party!")
    print("Get a blanket.\n")


print("We can just give the function members directly:")
cheese_and_crackers(20, 30)

print("OR, we can use variables from our script")
amount_of_cheese = 20
amount_of_boxes_pf_crackers = 30
cheese_and_crackers(amount_of_cheese, amount_of_boxes_pf_crackers)

print("We can even do math inside too:")
cheese_and_crackers(10+20, 5+6)

print("And we can combine the two, variable and math")
cheese_and_crackers(amount_of_cheese+100, amount_of_boxes_pf_crackers+1000)

print("Also, input is still ok:")
our_cheese = int(input(">"))
our_boxes = int(input(">"))
cheese_and_crackers(our_cheese, our_boxes)
