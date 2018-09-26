# A list of contributors

The following is a list of utility factors that contributed to the development of this project:

* The *Hacker News* users in this [post](https://news.ycombinator.com/item?id=17883409) who provided feedback data which was used to improve the matrix multiplication library's documentation and direction.
  * Hacker News user Boxxed who suggested the need for clarifying how to allocate memory for `Matrix` structs.
  * Hacker News user programmarchy who suggested the need for a testing paradigm and the need for clarifying the project's goals of learning and simplicity.
  * Hacker News user p1esk who suggested comparing the library's speed-wise performance to other implementations.
  * Hacker News user ychen306 who suggested the use of tiling for matrix multiplication.
  * Hacker News user alfalfasprout who noted the speed-wise performance of using naïve GEMM compared to tiling for the matrix multiplication of the library's small matrices.
* GitHub user [mistnim](https://github.com/mistnim) who raised the important [issue](https://github.com/webDva/matrixmul/issues/2) of matrices being multiplied incorrectly.
* The *Reddit* users in this [post](https://www.reddit.com/r/embedded/comments/9i6klr/im_making_a_portable_matrix_multiplication_library/) who provided data and feedback and assisted in the project's direction with their cooperation.
  * Reddit user Scottapotamas who suggested the use of QEMU for testing, offered to help procure a physical microcontroller, and provided guidance on the issue of optimization.
  * Reddit user lordlod who suggested the need for further specifying and clarifying the project's goals and vision.
  * Reddit user VectorPotential who raised the issue of supporting fixed-point arithmetic for the sake of facilitating portability and who requested the feature of matrix inversion.
  * Reddit user CJKay93 who mentioned the use of enabling software-based floating point for microcontrollers with no floating point unit.
  * Reddit users OnkelDon and ikatono who raised the issue of the disadvantages of using a header-only paradigm for the library.