---
layout: project
title: OreSat Deployable Antennas
sponsor: OreSat (via Portland State Aerospace Society)
sponsor_url: http://oresat.org/
document-date: 26 May 2018
academic-year: 2018
summary: Design antenna systems that will deploy from a CubeSat in low Earth orbit
---

## Project Objective

Design, test, and manufacture two communication antenna packages and their deployment systems for Oregon's first satellite (OreSat) with support from the Oregon Space Grant Consortium (OSGC).

## Team

![Oresat Deployable Antenna Team]( {{ "/projects/2018/images/PSAS_OreSat_team.png" | absolute_url }} )

The 2018 OreSat Deployable Antenna Team

* [Justin Burris](mailto:burris2@pdx.edu)
* [Shivani Nadarajah](mailto:shivani@pdx.edu)
* [John George](mailto:george22@pdx.edu)
* [Calvin Young](mailto:youngcal@pdx.edu)
* [Paijanne Jones](mailto:paijanne@pdx.edu)

## Customer / Market Requirements

![Oresat Deployable Antenna Team]( {{ "/projects/2018/images/PSAS_OreSat_satellite.png" | absolute_url }} )

OreSat relies on two separate antenna systems.  The **helical antenna** is a high-gain, directional downlink that is designed to send a high-definition video signal to handheld receivers build by Oregon high school students.  The **turnstile**, mounted on the other end of the satellite, is a suite of omnidirectional antennas designed to communicate with a ground control transmitter that will be stationed on top of the 4th Avenue Building.  Both antennas must be stowed for launch before being deployed in low Earth orbit.  OreSat is designed to conform with the [CubeSat Design Specifications](https://static1.squarespace.com/static/5418c831e4b0fa4ecac1bacd/t/56e9b62337013b6c063a655a/1458157095454/cds_rev13_final2.pdf) outlined by California Polytechnic State University.  It must also comply with the strict [environmental standards](https://standards.nasa.gov/standard/gsfc/gsfc-std-7000) imposed by NASA.  

The design must be extremely conservative in order to ensure reliability.  It must also be extremely frugal, using as little space and mass as possible.  

## Design Challenges

The satellite measures 100 x 100 x 227 mm and must weigh less than 2.66 kg which means that the stowed antennas (and their deployment mechanisms) must be as small as possible.  The helical antenna must compress down to a stowed height of less than 15 mm and deploy to a full length of 462 mm.  Its shape must be well controlled and it must be able to recover from bending moments imparted by the Attitude Control System (the focus of a 2018 Electrical Engineering capstone) as it orients the satellite in space.  The turnstile must deploy four separate structural members, each of which host a number of copper traces that transmit various electromagnetic signals.  Both antenna systems will be stowed for upwards of six months as we await the rocket launch.  OreSat will be subjected to massive vibrations as it ascends towards the International Space Station.  Once released into the extreme temperatures (ranging from -50 to +130 C) and hard vacuum of space, both systems have a single change to deploy; there are no opportunities to intervene with the automated systems.  

Each system relies on its own burnwire mechanism to release the stowed antennas; each antenna is held in compression by a monofilament line which is strung across a resistive element.  Upon receiving a signal, the system severs the burnwire which allows the antennas to deploy using their stored potential energy.  In order to remain as reliable and coherent as possible, each antenna system should rely on no more than a single burnwire each; attempting to synchronize the release of multiple burnwires is not feasible and using multiple burnwires to constrain a single system yields additional points of failure on a mission-critical system.  

## Outcomes

A full factor design of experiment was conducted on the burnwire mechanism and its sensitivity to vacuum conditions with various line thicknesses and resistance values.  The results of the experiments were reassuring: even at under the worst conditions we were able to sever the burnwire in a very short time while staying within our energy budget.  

We were excited to take our mechanisms into a local laboratory that offered to assist our team with vibration testing and analysis.  It quickly became apparent that such an endeavor is worthy of its own capstone - even with such incredible resources at our disposal.  Unfortunately, there will not be time for more than a first run at analysis and testing of the two systems.

#### Turnstile Array

The turnstile array went through several iterations of a design prototype and was nearing completion when the scope of the project was changed by the sponsor.  The team quickly revived and updated an older design concept based on an array of four bistable mechanical strips.  The new requirements necessitated a reorientation of the system which resulted in the mechanism taking up more space than the previous design, posing new integration challenges.  The original design used the mechanical members as the conductive element for the antennas whereas the revised system needs a non-conductive structure.  Instead of a metallic poles, the turnstile will be constructed using thin strips of copper embedded in a bistable layup of fiberglass.  Sourcing the right aerospace-grade material has proven to be a major challenge, with lead times measured in weeks.  Nevertheless, the concept is proven and we will spend the rest of the year testing different weave orientations and material combinations.  

![Turnstile Array]({{ "/projects/2018/images/PSAS_OreSat_turnstile.png" | absolute_url }})

#### Helical Antenna

We put a substantial amount of work went into designing the helical antenna itself - long before we got started on the deployment mechanism.  Running MATLAB simulations helped us get a better understanding of the propagation patterns and signal strengths that different designs offered.  Research was done to establish whether we could alter the shape of the helix to compress it beyond its stacked column height.  In the end, we put that fundamental research aside and decided to focus on designing a deployment system around a simple helix - otherwise we would not have had the time to design the deployment system at all.  The many attempts made to wind the helix by hand were met with varying results.  We ultimately turned to a local manufacturer who was capable of making a compression spring of such exotic proportions.  The results were fantastic.  Research into competing designs influenced our decision making process for the overall architecture of the release mechanism.  We settled on a simple design that consists of three hinges which release in unison as a single burnwire is severed.  The team has been iterating on various manifestations of this design in an attempt to create a mechanism that will flawlessly release the compressed spring with minimal risk of entanglement.  Once released, the helix relies on a system of tethers to constrain its length.  By keeping the deployed antenna in a state of partial compression, the tethers are held in tension which provides stiffness to the structure which adds a significant damping force to the antenna should it begin to oscillate in response to a change in rotational acceleration caused by the Attitude Control System.  After cycling through a number of designs, the team ultimately settled on using thin polyamide strips for the tether system.  This solution keeps the structure as simple, compact, and lightweight as possible.  Additional research will establish a space-ready method for bonding strips of the material together for the final flight hardware.  

![Helical Antenna]({{ "/projects/2018/images/PSAS_OreSat_helical.png" | absolute_url }})

## Acknowledgments

Special thanks to everyone who has helped make this project a success:

* **Andrew Greenberg** and **Glenn LeBrasseur** for sponsoring the project and herding all of the electrons
* **Gerald Recktenwald** for providing fantastic guidance as our faculty advisor
* **Dependable Springs** for the precise manufacturing of our helical antennas
* **HP Dynamics Lab** for their generous assistance with all things vibration
* **HP Model Shop** for supplying high-quality 3D prints of our design prototypes



