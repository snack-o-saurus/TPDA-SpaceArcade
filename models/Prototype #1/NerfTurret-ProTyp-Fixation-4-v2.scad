$fn = 300;

//Halterung NERF
 rotate([0,90,0]){
 difference(){  cylinder(10,6,6,center=true);  
                cylinder(11,5,5,center=true);}}
                
//Nerfhalter v.2 [Anforderungen prov. by Oos, 
//neuer Prototyp sei erforderlich zur Druckoptimierung]
// >>24/5/22
//------------------------------------------------------------
//VL                
translate([-14,10,39]){ rotate([-15,-20,0]){
  cube([5,5,75],center=true);   }}
//VR
translate([14,10,39]){ rotate([-15,20,0]){
  cube([5,5,75],center=true);   }}
//HL
translate([-14,-10,39]){ rotate([15,-20,0]){
  cube([5,5,75],center=true);   }}
//HR
translate([14,-10,39]){ rotate([15,20,0]){
  cube([5,5,75],center=true);   }}
//RL
difference(){
translate([-26.5,0,72]){  rotate([0,0,0]){
  cube([5,100,5],center=true);  }}
translate([-30,-40,72]){   rotate([0,0,0]){
  cube([7,25,7],center=true);   }}
translate([0,-44,72]){   rotate([0,90,0]){
 cylinder(60,0.75,0.75,center=true);  }}
translate([0,-34,72]){   rotate([0,90,0]){
 cylinder(60,0.75,0.75,center=true);  }}}
//RR
  difference(){
translate([26.5,0,72]){  rotate([0,0,0]){
  cube([5,100,5],center=true);  }}
translate([30,-40,72]){  rotate([0,0,0]){
  cube([7,25,7],center=true);   }}
translate([0,-44,72]){   rotate([0,90,0]){
 cylinder(60,0.75,0.75,center=true);  }}
translate([0,-34,72]){   rotate([0,90,0]){
 cylinder(60,0.75,0.75,center=true);  }}}
//LC
translate([-12.5,30,67]){    rotate([-15,0,-45]){
    cube([5,40,5],center=true); }}
translate([12.5,30,67]){    rotate([-15,0,45]){
    cube([5,40,5],center=true); }}
//STC
translate([-13,39,86]){   rotate([-66,45,0]){
    cube([5,43,5],center=true); }}
translate([13,39,86]){   rotate([-66,-45,0]){
    cube([5,43,5],center=true); }}
//---------------------------------------------------------
//Back frame
translate([-150,0,0]){    union(){
translate([40,-33,15]){  rotate([90,0,0]){
    cylinder(60,4,4,center=true);}}
translate([0,-33,15]){  rotate([90,0,0]){
    cylinder(60,4,4,center=true);}}
translate([20,-60,15]){  rotate([90,0,90]){
    cylinder(45,4,4,center=true);}}
translate([15,-45,15]){  rotate([90,0,45]){
    cylinder(45,2,2,center=true);}}
translate([25,-45,15]){  rotate([90,0,-45]){
    cylinder(45,2,2,center=true);}}
translate([0,-33,10]){  rotate([80,0,0]){
    cylinder(62,3,3,center=true);}}
    
difference(){
translate([44,8.8,15]){  rotate([0,0,0]){
   cube([2.5,25,5],center=true);}}
translate([44,15,15]){  rotate([0,90,0]){
   cylinder(50,1.45,1.45,center=true);}}
translate([44,5,15]){  rotate([0,90,0]){
   cylinder(50,1.45,1.45,center=true);}}
}
difference(){
translate([-6,8.8,15]){  rotate([0,0,0]){
   cube([2.5,25,5],center=true);
}}
translate([-6,15,15]){  rotate([0,90,0]){
   cylinder(50,1.45,1.45,center=true);}}
   
translate([-6,5,15]){  rotate([0,90,0]){
   cylinder(50,1.45,1.45,center=true);}}
}


translate([-2.5,-15.5,15]){  rotate([0,0,0]){
   cube([12,25,10],center=true);
}}

//Aufnahme fuer Triggerservo
difference(){
translate([42,-27.9,8]){cube([6,50,24],center=true);}
translate([42,-27.9,4]){cube([10,22,11],center=true);}
translate([42,-16,4]){  rotate([0,90,0]){
    cylinder(8,0.5,0.5,center=true);}}
translate([42,-40,4]){  rotate([0,90,0]){
    cylinder(8,0.5,0.5,center=true);}}
}
}}