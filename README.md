# CoffeeMachineDunzo

Command to Run:

./CoffeeMachine.exe

Output:

||  coffeeSyrup         ||  20       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  20       ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  

Testing serving a single beverage with insufficient quantity
Ingredients before serving black_tea
||  coffeeSyrup         ||  20       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  20       ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  

black_tea cannot be prepared because gingerSyrup is not sufficient
||  coffeeSyrup         ||  20       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  20       ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  


Testing Refilling the machine
Ingredients before refill : 
||  coffeeSyrup         ||  20       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  20       ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  


Ingredients after refill : 
||  coffeeSyrup         ||  40       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  20       ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  


Testing serving a single beverage
Ingredients before serving ginger_tea
||  coffeeSyrup         ||  40       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  20       ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  

ginger_tea is prepared
Ingredients after serving : 
||  coffeeSyrup         ||  40       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  0        ||  (LOW) 
||  hotMilk             ||  490      ||  
||  hotWater            ||  450      ||  
||  sugarSyrup          ||  90       ||  
||  teaLeavesSyrup      ||  90       ||  


Testing Refilling the machine with multiple ingredients
Ingredients before refill : 
||  coffeeSyrup         ||  40       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  0        ||  (LOW) 
||  hotMilk             ||  490      ||  
||  hotWater            ||  450      ||  
||  sugarSyrup          ||  90       ||  
||  teaLeavesSyrup      ||  90       ||  


Ingredients after refill : 
||  coffeeSyrup         ||  40       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  40       ||  
||  hotMilk             ||  990      ||  
||  hotWater            ||  950      ||  
||  sugarSyrup          ||  90       ||  
||  teaLeavesSyrup      ||  90       ||  


Testing serving multiple beverages
Ingredients before serving hot_tea
||  coffeeSyrup         ||  40       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  40       ||  
||  hotMilk             ||  990      ||  
||  hotWater            ||  950      ||  
||  sugarSyrup          ||  90       ||  
||  teaLeavesSyrup      ||  90       ||  

hot_tea is prepared
Ingredients before serving black_tea
||  coffeeSyrup         ||  40       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  30       ||  
||  hotMilk             ||  890      ||  
||  hotWater            ||  750      ||  
||  sugarSyrup          ||  80       ||  
||  teaLeavesSyrup      ||  60       ||  

black_tea cannot be prepared because gingerSyrup is not sufficient
Ingredients before serving green_tea
||  coffeeSyrup         ||  40       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  30       ||  
||  hotMilk             ||  890      ||  
||  hotWater            ||  750      ||  
||  sugarSyrup          ||  80       ||  
||  teaLeavesSyrup      ||  60       ||  

green_tea cannot be prepared because green_mixture is not available
Ingredients before serving hot_coffee
||  coffeeSyrup         ||  40       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  30       ||  
||  hotMilk             ||  890      ||  
||  hotWater            ||  750      ||  
||  sugarSyrup          ||  80       ||  
||  teaLeavesSyrup      ||  60       ||  

hot_coffee is prepared
Ingredients after serving : 
||  coffeeSyrup         ||  30       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  30       ||  
||  hotMilk             ||  880      ||  
||  hotWater            ||  700      ||  
||  sugarSyrup          ||  70       ||  
||  teaLeavesSyrup      ||  60       ||  


Testing serving a single beverage with unavailable ingredient
Ingredients before serving green_tea
||  coffeeSyrup         ||  30       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  30       ||  
||  hotMilk             ||  880      ||  
||  hotWater            ||  700      ||  
||  sugarSyrup          ||  70       ||  
||  teaLeavesSyrup      ||  60       ||  

green_tea cannot be prepared because green_mixture is not available
||  coffeeSyrup         ||  30       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  30       ||  
||  hotMilk             ||  880      ||  
||  hotWater            ||  700      ||  
||  sugarSyrup          ||  70       ||  
||  teaLeavesSyrup      ||  60       ||  


Testing Refilling the machine with new ingredient
Ingredients before refill : 
||  coffeeSyrup         ||  30       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  30       ||  
||  hotMilk             ||  880      ||  
||  hotWater            ||  700      ||  
||  sugarSyrup          ||  70       ||  
||  teaLeavesSyrup      ||  60       ||  


Ingredients after refill : 
||  coffeeSyrup         ||  30       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  30       ||  
||  green_mixture       ||  100      ||  
||  hotMilk             ||  880      ||  
||  hotWater            ||  700      ||  
||  sugarSyrup          ||  70       ||  
||  teaLeavesSyrup      ||  60       ||  

