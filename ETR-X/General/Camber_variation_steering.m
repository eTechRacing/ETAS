clear all
close all
clc

% Dades:
data= xlsread('Steering-Camber.xlsx');
steering= data(:, 1);%deg
camber= data(:, 2);%deg
mat= [steering, camber];

