$fn=150; //Auflösung

//Erstellen der Grundplatte mit Nut
union(){    difference(){
cube([200,180,40], center=true);
//Aussparung für PAN-Servomotor 
 translate([60,60,0]){cube([29,29,45], center=true);} 
 translate([60,85,-22]){cube([5,25,10], center=true);}
 
 //Nut
 translate([0,0,37]){    
  difference(){   
    cylinder(h=40,r=50, center=true);
    cylinder(h=40,r=45, center=true); }}}
    
translate([44.5,60,22]){cube([2,30,5], center=true); } 
translate([75.5,60,22]){cube([2,30,5], center=true); } 
//Top plate for engine screwdown       
difference(){  
 translate([60,60,25]){cube([33,30,2], center=true);}  
    // 1/1000 clearance for engine shaft 
 translate([60,60,25]){cylinder(5, 2.6, center=true);}
    //Screwdown points
 translate([50,70,25]){cylinder(5, 2.5, center=true);}
 translate([70,70,25]){cylinder(5, 2.5, center=true);}
 translate([70,50,25]){cylinder(5, 2.5, center=true);}
 translate([50,50,25]){cylinder(5, 2.5, center=true);}
 }
}