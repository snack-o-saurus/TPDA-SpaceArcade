$fn = 200;

//Halterung NERF
translate([100,0,10]){ rotate([0,90,0]){
 difference(){  cylinder(10,6,6,center=true);  
                cylinder(11,5,5,center=true);}}}
//VL
difference(){
translate([89,13,50]){ rotate([-15,-15,0]){
  cylinder(77,2.5,2.5,center=true);}}
translate([100,0,10]){ rotate([0,90,0]){
 cylinder(11,5,5,center=true);}}}
//VR
 difference(){
translate([111,13,50]){ rotate([-15,15,0]){
    cylinder(77,2.5,2.5,center=true);}}
translate([100,0,10]){ rotate([0,90,0]){
 cylinder(11,5,5,center=true);}}}
//HL
 difference(){
translate([89,-13,50]){ rotate([15,-15,0]){
    cylinder(77,2.5,2.5,center=true);}}
translate([100,0,10]){ rotate([0,90,0]){
 cylinder(11,5,5,center=true);}}}
//HR
 difference(){
translate([111,-13,50]){ rotate([15,15,0]){
    cylinder(77,2.5,2.5,center=true);}}
translate([100,0,10]){ rotate([0,90,0]){
 cylinder(11,5,5,center=true);}}}
//-- SEC R -- >>SCREW HOLE ID: 5mm
difference(){
translate([120,0,85]){  rotate([90,0,0]){
   cylinder(140,4,4,center=true);}}
translate([120,-60,85]){  rotate([90,0,0]){
   cylinder(25,2.5,2.5,center=true);}}}
//LOWER RIGHT
translate([111,4,50]){ rotate([-45,15,0]){
  cylinder(36,2.5,2.5,center=true);}}
translate([114,-5,62]){ rotate([32,15,0]){
  cylinder(55,2.5,2.5,center=true);}}
//-- SEC L -- >>SCREW HOLE ID: 5mm
difference(){
 translate([80,0,85]){  rotate([90,0,0]){
   cylinder(140,4,4,center=true);}}
 translate([80,-60,85]){  rotate([90,0,0]){
   cylinder(25,2.5,2.5,center=true);}}}
//LOWER LEFT
translate([89,4,50]){ rotate([-45,-15,0]){
  cylinder(36,2.5,2.5,center=true);}}
translate([86,-5,62]){ rotate([32,-15,0]){
  cylinder(55,2.5,2.5,center=true);}}
//-- FRAME FRONT: STRUTS --
translate([100,17.25,65]){  rotate([0,90,0]){
   cylinder(32,2.5,2.5,center=true);}}
translate([100,26,85]){  rotate([0,90,0]){
   cylinder(40,3,3,center=true);}}
translate([100,46,85]){  rotate([45,90,0]){
   cylinder(60,3,3,center=true);}}
translate([100,46,85]){  rotate([-45,90,0]){
   cylinder(60,3,3,center=true);}}
translate([100,67,85]){  rotate([0,90,0]){
   cylinder(44,4,4,center=true);}}
//FRONT TIEDOWNS #1
translate([86,55,100]){  rotate([-45,25,0]){
   cylinder(40,2,2,center=true);}}
translate([114,55,100]){  rotate([-45,-25,0]){
   cylinder(40,2,2,center=true);}}
translate([100,68,112]){  rotate([0,90,0]){
   cylinder(20,2,2,center=true);}}
//FT #2
translate([86,45,100]){  rotate([-45,25,0]){
   cylinder(40,2,2,center=true);}}
translate([114,45,100]){  rotate([-45,-25,0]){
   cylinder(40,2,2,center=true);}}
translate([100,58,112]){  rotate([0,90,0]){
   cylinder(20,2,2,center=true);}}   
//FRAME BACK TILT CONNECTOR >> PIN CONNECTOR ID: ~3mm
translate([100,-9.5,38]){  rotate([0,90,0]){
   cylinder(19,2.5,2.5,center=true);}}
difference(){
translate([100,-7,31]){   rotate([108,0,0]){
    cube([4,20,6],center=true);}}
translate([98,-8,28]){   rotate([108,0,0]){
    cube([4,10,6],center=true);}}}
difference(){
translate([101,-11,26]){   rotate([108,0,0]){
    cube([2,13,6],center=true);}}
translate([101,-16,30]){   rotate([75,0,0]){
    cube([4,12,6],center=true);}}
translate([101,-10,18]){   rotate([170,0,0]){
    cube([4,12,6],center=true);}}}
translate([99,-11,27]){  rotate([0,90,0]){
   cylinder(2.5,1.6,1.25,center=true);}}
   
//--------------------------------------------------------
//Fixation pin 5mm   
 translate([0,50,2.5]){   rotate([0,90,0]){
   cylinder(50,2.5,2.5,center=true);}}  
   
//--------------------------------------------------------
// Servo trigger mount
//Left connector pin
difference(){
translate([0,0,10]){cube([10,6,20],center=true);}
translate([0,0,3.5]){  rotate([0,90,0]){
    cylinder(15.2,2.5,2.5,center=true);}}
}
translate([0,10,15]){  rotate([90,0,0]){
    cylinder(15.2,2.5,2.5,center=true);}}
//Right connector pin
difference(){
translate([40,0,10]){cube([10,6,20],center=true);}
translate([40,0,3.5]){  rotate([0,90,0]){
    cylinder(15.2,2.5,2.5,center=true);}}
    }
translate([40,10,15]){  rotate([90,0,0]){
    cylinder(15.2,2.5,2.5,center=true);}}
//Back frame 
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
//Aufnahme fuer Triggerservo
difference(){
translate([42,-27.9,8]){cube([6,50,24],center=true);}
translate([42,-27.9,4]){cube([10,22,11],center=true);}
translate([42,-16,4]){  rotate([0,90,0]){
    cylinder(8,0.5,0.5,center=true);}}
translate([42,-40,4]){  rotate([0,90,0]){
    cylinder(8,0.5,0.5,center=true);}}
}