.. Benchmark Arduino Mega 2560 documentation master file, created by
   sphinx-quickstart on Sun Jan  5 08:22:54 2025.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Benchmark Arduino Mega 2560
===========================

**Benchmark for Arduino Mega 2560** is a IoT tool developed by `AgroTechLab <https://agrotechlab.lages.ifsc.edu.br>`_ (*Technology Development 
Laboratory for Agribusiness*) of `IFSC <https://www.ifsc.edu.br>`_ (*Federal Institute of Santa Catarina*).

It aims to get data about the energy consumption of Arduino Mega 2560 in different operation modes. It can be used in conjunction 
with a power consumption analysis tool such as `Power Monitor <https://github.com/AgroTechLab-IFSC/power_monitor>`_.

The following modes are provided in order to test energy consumption:

   - **BENCHMARK_MODE_0**
      - Duty cycle: 100%
      - Default arduino project configuration;
      - Builtin LED on;
   - **BENCHMARK_MODE_1**
   - **BENCHMARK_MODE_2**
   - **BENCHMARK_MODE_3**
   - **BENCHMARK_MODE_4**

Versions support
----------------

Updates and new features are constantly being added to **Power Monitor**. The following table shows the supported versions:

.. table::
   :align: center
   :widths: 20 20 20   

   +---------+------------+--------------+
   | Version |  Security  | New features |
   +=========+============+==============+
   |  0.x.x  |     Yes    |     Yes      |
   +---------+------------+--------------+

.. toctree::
   :name: mastertoc
   :maxdepth: 2
   :caption: Table of Contents:

   authors_license
   changelog
   hw_req
   source_code_docs

