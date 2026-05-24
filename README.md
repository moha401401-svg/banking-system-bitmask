<div align="center">
  <img src="https://capsule-render.vercel.app/render?type=waving&color=auto&height=220&section=header&text=Secure%20Banking%20System&fontSize=40&animation=fadeIn&fontAlignY=38" width="100%" />
</div>

<br>

<div align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B" />
  <img src="https://img.shields.io/badge/Paradigm-Object--Oriented%20(OOP)-green?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Architecture-Bitmask%20ACL-orange?style=for-the-badge" />
</div>

<hr>

<h2>📖 Project Overview</h2>
<p>
This is a secure, production-grade <b>Console-Based Core Banking & Currency Exchange System</b> built completely from scratch using <b>Pure C++</b>. The project is specifically engineered to demonstrate master-level proficiency in <b>Object-Oriented Programming (OOP)</b> principles, low-level memory efficiency via <b>Bitwise operations</b>, and clean software architecture.
</p>

<hr>

<h2>🏗️ Object-Oriented Programming (OOP) Architecture</h2>
<p>The system completely avoids procedural scripting, relying heavily on a deeply structured class hierarchy, data encapsulation, and robust separation of concerns:</p>

<details open>
<summary><b>👥 Core Class Hierarchy & Inheritance (Click to collapse)</b></summary>
<br>
<ul>
  <li><b><code>clsPerson</code> (Abstract Base Class):</b> Acts as the foundational blueprint containing protected attributes like <code>FirstName</code>, <code>LastName</code>, <code>Email</code>, and <code>Phone</code>, enforcing strict encapsulation.</li>
  <li><b><code>clsClient</code> (Derived Class):</b> Inherits from <code>clsPerson</code> to represent bank account holders, encapsulating banking data like <code>AccountNumber</code>, <code>PinCode</code>, and <code>AccountBalance</code>.</li>
  <li><b><code>clsUser</code> (Derived Class):</b> Inherits from <code>clsPerson</code> to represent bank employees, implementing credentials management and the <code>Permissions</code> integer mask.</li>
</ul>
</details>

<details>
<summary><b>Encapsulation & Data Persistence</b></summary>
<br>
<ul>
  <li>All class properties are secured using <code>private</code> or <code>protected</code> access modifiers, exposed safely via public <code>Get</code> and <code>Set</code> methods.</li>
  <li><b>File Infrastructure:</b> Data serialization and deserialization are handled within UI-independent file streams, converting raw text database records into runtime Objects seamlessly using <b>Relative Paths</b>.</li>
</ul>
</details>

<hr>

<h2>💻 System Modules & Main Menu</h2>
<p align="center">
  <marquee direction="right" scrollamount="4" style="color: #007acc; font-weight: bold;">⚡ Fully-featured Banking System containing 10 robust operational screens ⚡</marquee>
</p>

<blockquote>
  <code>[1] Add New Client</code> | <code>[2] Show Client List</code> | <code>[3] Update Client Info</code><br>
  <code>[4] Delete Client</code> | <code>[5] Find Client</code> | <code>[6] Transactions Module</code><br>
  <code>[7] Manage Users</code> | <code>[8] Login Register Log</code> | <code>[9] Currency Exchange</code><br>
  <code>[10] Logout</code>
</blockquote>

<hr>

<h2>⚡ Advanced Technical Features</h2>

<details>
<summary><b>🔐 Bitwise Permission System (Bitmasking Access Control)</b></summary>
<br>
Instead of using massive arrays or database joins, user access rights are evaluated at the CPU bit-level. Every function maps to a <b>Power of 2 (Bit Flag)</b>. An Admin with full clearance is assigned a permission value of <code>-1</code>, which flips all bits to true <code>(11111111)</code> in binary, instantly granting absolute access.
</details>

<details>
<summary><b>💱 Currency Exchange Engine</b></summary>
<br>
A standalone module structured around a <code>clsCurrency</code> object layer that pulls system exchange rates, handles geometric cross-currency conversions, and synchronizes international balances.
</details>

<details>
<summary><b>📝 Security Auditing (Login Register)</b></summary>
<br>
Implements an audit trail by logging every single user login session with precise timestamps and session snapshots directly into a tracking ledger database file.
</details>

<hr>

<h2>📊 Bitwise Permission Mapping (Bit Flags)</h2>

<table width="100%">
  <thead>
    <tr style="background-color: #1f2328; color: white;">
      <th>Option</th>
      <th>System Module / Permission</th>
      <th>Binary Bit Flags</th>
      <th>Decimal Value</th>
      <th>Access Rights Enforced</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><b>[1]</b></td>
      <td>Add New Client</td>
      <td><code>0000000001</code></td>
      <td><b>1</b></td>
      <td>Permission to execute client inserts</td>
    </tr>
    <tr>
      <td><b>[2]</b></td>
      <td>Show Client List</td>
      <td><code>0000000010</code></td>
      <td><b>2</b></td>
      <td>Permission to view sensitive records</td>
    </tr>
    <tr>
      <td><b>[3]</b></td>
      <td>Update Client Info</td>
      <td><code>0000000100</code></td>
      <td><b>4</b></td>
      <td>Permission to alter balance properties</td>
    </tr>
    <tr>
      <td><b>[4]</b></td>
      <td>Delete Client</td>
      <td><code>0000001000</code></td>
      <td><b>8</b></td>
      <td>Permission to purge data indices</td>
    </tr>
    <tr>
      <td><b>[5]</b></td>
      <td>Find Client</td>
      <td><code>0000010000</code></td>
      <td><b>16</b></td>
      <td>Permission to trigger query filters</td>
    </tr>
    <tr>
      <td><b>[6]</b></td>
      <td>Transactions Module</td>
      <td><code>0000100000</code></td>
      <td><b>32</b></td>
      <td>Access to Ledger (Deposit/Withdraw/Transfer)</td>
    </tr>
    <tr>
      <td><b>[7]</b></td>
      <td>Manage Users</td>
      <td><code>0001000000</code></td>
      <td><b>64</b></td>
      <td>Access to system employee control panels</td>
    </tr>
    <tr>
      <td><b>[8]</b></td>
      <td>Login Register Log</td>
      <td><code>0010000000</code></td>
      <td><b>128</b></td>
      <td>Access to security audit trails</td>
    </tr>
    <tr>
      <td><b>[9]</b></td>
      <td>Currency Exchange</td>
      <td><code>0100000000</code></td>
      <td><b>256</b></td>
      <td>Access to currency marketplace updates</td>
    </tr>
    <tr style="background-color: #f6f8fa; font-weight: bold;">
      <td><b>[-]</b></td>
      <td>Full Access (Super Admin)</td>
      <td><code>1111111111</code></td>
      <td><span style="color: red;"><b>-1</b></span></td>
      <td>Flips all evaluation bits to True</td>
    </tr>
  </tbody>
</table>

<hr>

<h2>🚀 Execution & Live Testing</h2>

<table>
  <tr>
    <td>
      <h3>⚙️ How to Run Locally:</h3>
      <ol>
        <li>Clone the repository.</li>
        <li>Ensure all database <code>.txt</code> files sit in the same working directory as your binaries (Relative Path protection enabled).</li>
        <li>Compile using any modern C++ Compiler standard (GCC, Clang, MSVC).</li>
      </ol>
    </td>
    <td width="50%">
      <h3>🔑 Default Master Credentials:</h3>
      <ul>
        <li><b>Username:</b> <code>hokvok12</code></li>
        <li><b>Password:</b> <code>A</code></li>
      </ul>
      <p><i>Use these credentials upon terminal execution to bypass the security screen and test all restricted operations.</i></p>
    </td>
  </tr>
</table>

<br>
<div align="center">
  <img src="https://capsule-render.vercel.app/render?type=waving&color=auto&height=100&section=footer" width="100%" />
</div>
