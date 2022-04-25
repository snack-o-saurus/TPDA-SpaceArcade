$fn=500; //Auflösung

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
//------------------------------------------------------------
 //Turmteil inkls Feder für Grundplatte
 translate([200,0,105]){
 cylinder(180, 65, 50, center=true); }
 translate([200,0,16]){     difference(){   
    cylinder(h=10,r=50, center=true);
    cylinder(h=10.5,r=45, center=true);}}
 //Servo-Anbindung PAN
 translate([123,0,35]){cube([30,14,8], center=true); }
 translate([118,0,31]){cylinder(5,3.5,3,center=true);}
 //Turret für TILT-Aufnahme der Nerf
 difference(){
 translate([180,0,210]){ rotate([0,90,0]){
     cylinder(60, 50, 50, center=true);}}
 //Bohrung fuer 10mm-Verbindungsstift
 translate([170,17.5,228]){ rotate([0,90,0]){
   cylinder(50, 5, 5, center=true);} }
 translate([166,-25,225]){
     cube([33,29,29],center=true);}
 translate([178,-25,225]){  rotate([0,90,0]){
     cylinder(25,2.5,2.5,center=true);}}
 translate([199,-20,238]){rotate([-40,0,0]){
     cube([30,38,104],center=true);}}
 translate([199,-15,230]){rotate([-75,0,0]){
     cube([30,38,120],center=true);}}
 }
 difference(){
translate([230,0,210]){ rotate([0,90,0]){
   cylinder(40, 50, 50, center=true);}}
//Bohrung fuer 10mm-Verbindungsstift B-Side
translate([230,17.5,228]){ rotate([0,90,0]){
   cylinder(50, 5, 5, center=true);}}
  }  
   
//-----------------------------------------------------------
//Adapter fuer Motorwelle
difference(){
translate([-200,0,0]){cube([25,10,2], center=true);}
translate([-200,8,0]){
    rotate([0,0,10]){cube([40,10,3], center=true);}}
translate([-200,-8,0]){
    rotate([0,0,-10]){cube([40,10,3], center=true);}}
translate([-191,0,0]){cylinder(12,2.5,2.5,true);}
}
translate([-202,0,3.5]){cylinder(5.5,2.5,2.5,true);}

//----------------------------------------------------------
//Verbindungsstange PAN
//TODO: Radien nach Spiel einstellen!!!
difference(){
translate([-140,0,0]){cube([8,120,4], center=true);}
translate([-140,55,0]){cylinder(20,2.5,2.6,center=true);}
translate([-140,-55,0]){cylinder(20,2.5,3.8,center=true);}
translate([-140,-55,0]){cylinder(20,3.8,2.5,center=true);}
}

//Halterung NERF
translate([400,0,10]){ rotate([0,90,0]){
 difference(){  cylinder(10,6,6,center=true);  
                cylinder(11,5,5,center=true);}}}
difference(){
translate([389,13,50]){ rotate([-15,-15,0]){
    cylinder(77,2.5,2.5,center=true);}}
translate([400,0,10]){ rotate([0,90,0]){
 cylinder(11,5,5,center=true);}}}
 difference(){
translate([411,13,50]){ rotate([-15,15,0]){
    cylinder(77,2.5,2.5,center=true);}}
translate([400,0,10]){ rotate([0,90,0]){
 cylinder(11,5,5,center=true);}}}
