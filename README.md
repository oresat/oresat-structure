# oresat-structure
Mechanical structure for OreSat

CAD requires <a href="https://github.com/oresat/reaction-wheels">Reaction-Wheels</a> be cloned into the same directory, e.g.:  

    OreSat/
     |-- reaction-wheels/
     |-- oresat-structure/

## TODO:  
- [ ] Get the UO team to choose a camera!
- [x] Fix the assembles/tech drawings to match Nanorack's convention of XYZ. (Helical goes on +Z. Backplane goes on -X) (@paperman5)
- [x] Create keepout volumes (parts in the assembly) that correspond to the CubeSat and Nanoracks specifications. (@jalouke)
- [ ] (Re)design the helical antenna. (@paperman5)
	- [ ] Model the strings that will keep the helical rigid.
- [ ] (Re)design the turnstile antenna. (@joedang)
    - [ ] Build a working mockup of the deployment.
- [ ] Fix/check connector alignment on the backplane. (@joedang)
- [ ] Modify space foam to not interfere with the screws that hold the frame together. (@RocketmanYG)
- [ ] Gather info on and/or bug ECEs about the kill switches and RBF (Remove Before Flight) tag. (@hmarie2)
- [ ] Consolidate all COTS parts into the COTS folder. 

## Directory Structure
- Backplane  
_The hub which provides power and data to all the boards_
- COTS  
_Any Commercial-Off-The-Shelf parts -- screws, connectors, et cetera._
- CardModules  
_Parts/subassemblies for the cameras. (due for renaming)_
- Generic  
_Parts/subassemblies for the generic card._
- Hardware  
_???_
- ~~HelicalCard~~ 
_~~Parts/subassemblies for the +Z (helical) antenna.~~ (merged into `Zpos/`)_
- Rack  
_The required CDS rails and the 'rack mount' panels -- the actual structure, per se_
- Solar  
_Solar panel modules_
- Zneg  
_The feet of the unicorn_
- Zpos  
_The horn of the unicorn_
- OreSat.SLDASM  
_The complete assembly of OreSat_
