classdef CONVERT < handle
%
% Class that encapsulates UNIT CONVERSION stuff.
% The UNIVERSE is rendered in System International (SI) units.
% Seconds       Time
% Meters        Distance
% Kilograms     Mass
% Kelvin        Temperature
% Ampere        Electric Current
% Mole          Amount of substance
% Candela
% Tesla (in SI base units: kilogram per second squared per ampere)
    
  properties (Constant)
    CM_PER_INCH    = 2.54;                       % This is exact.
    FEET_PER_METER = 3.032808398950131;          % Derived from CM_PER_INCH.
  end

end