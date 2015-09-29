
help deepmatching
deepmatching() % show some help about options
img1 = single(imread('liberty1.png'));
img2 = single(imread('liberty2.png'));
matches = deepmatching( img1, img2, '-downscale 2 -v');
matches % print matches, should be as the listing shown below