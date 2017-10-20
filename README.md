# oresat-structure
Mechanical structure for [OreSat](http://www.oresat.org)

This repo contains the top-level assembly of OreSat and the trivial subassemblies. If you'd like to contribute, drop in on the [Google hangout][hangout] (Fridays at 2 pm), [read the issues][issues], and/or read the [contributions guide.][contrib] 

The top-level assembly requires the [reaction wheels] repo be cloned into the same directory, e.g.:  

    OreSat/
     |-- reaction-wheels/
     |-- oresat-structure/

## TODO:  
- [X] Get the UO team to choose a camera!
- [x] Fix the assembles/tech drawings to match Nanorack's convention of XYZ. (Helical goes on +Z. Backplane goes on -X) (@paperman5)
- [x] Create keepout volumes (parts in the assembly) that correspond to the CubeSat and Nanoracks specifications. (@jalouke)
- [ ] (Re)design the helical antenna. (@paperman5)
	- [X] Model the strings that will keep the helical rigid.
	- Actually, it looks like this is going to become a capstone.
- [ ] (Re)design the turnstile antenna. (@joedang)
    - [ ] Build a working mockup of the deployment.
    - This is going to be part of the same capstone that does the helical antenna.
- [X] Fix/check connector alignment on the backplane. (@joedang)
- [ ] Modify space foam to not interfere with the screws that hold the frame together. (@RocketmanYG)
- [X] Gather info on and/or bug ECEs about the kill switches and RBF (Remove Before Flight) tag. (@hmarie2)
- [X] Consolidate all COTS parts into the COTS folder. 
- [ ] Update BoM with quantities.
- [ ] Design a board that can act as an adapter for a PC 104 board. (This will either require chopping some corners off of the PC 104 or adding cutouts to the frame.)
- [ ] Complete the inhibit switch assembly, using the measurements from the switches we ordered. 
	- [ ] Modify the inhibit switch plunger to only have one sloping side.

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

## Drawings
- [generic board (MME-style dimensions)](/Generic/Generic_board.pdf)
- [generic board (cartesian coordinates)](/Generic/Generic_board_electricallyUseful.pdf)
- [backplane board](/Backplane/Backplane_board.PDF) (MME style and Eagle style)



[reaction wheels]: https://github.com/oresat/reaction-wheels
[hangout]: http://www.psas.pdx.edu/hangout
[issues]: https://github.com/oresat/oresat-structure/issues
[contrib]: https://github.com/oresat/oresat-structure/blob/master/.github/CONTRIBUTING.md
[]: 
[]: 
[]: 
