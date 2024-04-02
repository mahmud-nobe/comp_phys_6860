## Final Project

### Relative Resonance Decay:

#### Kinematic information:

pT = 1,2,3 GeV/c of the resonance (or just a uniform distribution, for test purposes, I would start with a fixed pT
mass of resonance and decay particles according to PDG book. Assume both decay into a proton and a π−.
Lab frame: eta=[-0.5,0.5] (uniform), phi=isotropic, sqrt(sNN) = 200 GeV/c

(Lambda(1520) resonance)

#### Implement a relativistic resonance decay
**Monte Carlo Simulation**:
- Use the Lambda particle resonance (look up in PDG)
- Implement decay in resonance rest frame (isotropic decay)
- Boost in the center-of-mass frame of the collision using sqrt(sNN)=200 GeV/c
- Save this event (of course lots of them)

- Write an analysis macro: Invariant Mass calculation: to identify/confirm the resonance
- Additions:
i) implement gaussian smearing of uncertainties in momentum (mimic detector resolution)
ii) Add uncorrelated background


### Group 2 Members: 
- FNU Syed Faraz Mohd Mehdi
- Robert Dolan
- Wooyong Han
- Mahmud Un Nobe 
