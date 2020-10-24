
## pbrt 对所使用的几何光学模型的约定

In pbrt, we will assume that geometric optics is an adequate model for the description of light and light scattering. This leads to a few basic assumptions about the behavior of light that will be used implicitly throughout the system:

- *Linearity:* The combined effect of two inputs to an optical system is always equal to the sum of effects of each of the inputs individually.
- *Energy conservation:* When light scatters from a surface or from participating media, the scattering events can never produce more energy than they started with.
- *No polarization:* We will ignore polarization of the electromagnetic field; therefore, the only relevant property of light is its distribution by wavelength (or, equivalenty, frequency).
- *No fluorescence or phosphorescence:* The behavior of light at one wavelength is completely independent of light's behavior at other wavelengths or times. As with poplarization it is not too difficult to include these effects, but they would add relatively little practical value to the system.
- *Steady state:* Light in the environment is assumed to have reached equilibrium, so its radiance distribution isn't changing over time. This happens nearly instantaneously with light in realistic scens, so it is not a limitation in practice. Note that phosphorescene also violates the steady-state assumption.

The most significant loss from adopting a geometric optics model is that diffraction and interference effetts cannot easily be accounted for. As noted by Preisendorfer(1965), this is a hard problem to fix because, for example, the total flux over two isn't necessarily equal to the sum of the power received over each individual area in the presence of those effects.
