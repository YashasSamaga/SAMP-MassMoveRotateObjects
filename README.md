# SAMP-MassMoveRotateObjects
Takes input.pwn and gives output.pwn; corrects positions and rotations

#### Sample Input (input.pwn)

  ```CreateObject(1685, -30.56665, 61.68634, -4.64510,   0.00000, 0.00000, 178.53790);
  CreateObject(1685, -30.61328, 61.70898, -3.14183,   0.00000, 0.00000, 357.96332);
  CreateObject(1685, -27.43872, 58.34119, -3.16016,   0.00000, 0.00000, 178.88976);
  CreateObject(1685, -27.33105, 58.32916, -4.64510,   0.00000, 0.00000, 358.46124);
  CreateObject(1685, -25.49390, 58.29718, -3.14183,   0.00000, 0.00000, 359.07529);
  ```

#### Sample Output (output.pwn)

Correction Factors: 10.0 10.0 10.0 5.0 5.0 5.0

  ```CreateObject(1685,-20.56665, 71.68634, 5.3549, 5, 5, 183.5379);
  CreateObject(1685,-20.61328, 71.70898, 6.85817, 5, 5, 362.96332);
  CreateObject(1685,-17.43872, 68.34119, 6.83984, 5, 5, 183.88976);
  CreateObject(1685,-17.33105, 68.32916, 5.3549, 5, 5, 363.46124);
  CreateObject(1685,-15.4939, 68.29718, 6.85817, 5, 5, 364.07529);
  ```
