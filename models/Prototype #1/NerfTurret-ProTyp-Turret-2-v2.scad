$fn = 350;

translate([-200,0,-139.8]){   union(){
 //Turmteil inkls Feder für Grundplatte
 difference(){
 translate([200,0,105]){
 cylinder(180, 65, 50, center=true);}
translate([200,0,40]){
 cylinder(200,70,70,center=true);}
}
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
translate([230,17.5,228]){ rotate([0,90,0]){
   cylinder(50, 5, 5, center=true);}}
  }  
}}