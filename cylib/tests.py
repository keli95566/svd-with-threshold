from tSVD import *
import numpy as np
import random


def tSVD_test1(num_case, dtype="float"):
    #  random numbers are sampled using np.random.rand for an arbitrary shape,
    #  compare with the np.linalg.svd result
    assert(dtype == "float" or "int"), "expected dtype to be float or int"

    for j in range(num_case):

        print("--- case %s : random array ----" % str(j+1))
        r, c = random.randint(0, 100), random.randint(0, 100)

        if dtype == "float":
            a = np.random.rand(r, c)
        if dtype == "int":
            a = np.random.randint(0, 1000, (r, c))

        a = a.astype(np.float64)

        u1, s1, v1 = np.linalg.svd(a)
        u, s, v = partial_svd(a, 2, 0.001)

        n_e = s.shape[0]
        u_p, s_p, v_p = u1[:, :n_e], s1[:n_e], v1[:n_e, :]
        assert(u_p.shape == u.shape), "dimension of u should match with ground truth"
        assert(s_p.shape == s.shape), "dimension of u should match with ground truth"
        assert(v_p.shape == v.shape), "dimension of u should match with ground truth"

        for i in range(15):

            p = i  # precision

            u_p_r, s_p_r, v_p_r = np.abs(np.round(u_p,  p)), np.abs(
                np.round(s_p, p)), np.abs(np.round(v_p, p))

            u_r, s_r, v_r = np.abs(np.round(u_p, p)), np.abs(
                np.round(s_p, p)), np.abs(np.round(v_p, p))
            try:
                assert(np.array_equal(u_p_r, u_r)
                       ), "precision of u breaks at decimal %s" % str(p)
                assert(np.array_equal(s_p_r, s_r)
                       ), "precision of s breaks at decimal %s" % str(p)
                assert(np.array_equal(v_p_r, v_r)
                       ), "precision of v breaks at decimal %s" % str(p)
            except:

                print("case %s: precision until %s is correct" %
                      (str(a+1), str(p)))
        #print("test case %s passed" % str(j+1))


if __name__ == "__main__":

    print("========== tSVD Correction Tests ===========")

    num_test_case = 5
    dtype = "float"
    tSVD_test1(num_test_case, dtype)
    #tSVD_test1(num_test_case, "int")
