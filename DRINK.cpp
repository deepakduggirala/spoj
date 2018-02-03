#include<stdio.h>
#include<math.h>

#define cw 4.19
#define ci 2.09
#define em 335

int main()
{
	static double mi,mw;
	double ti,tw,x,y,z;
	while(1)
	{
		scanf("%lf%lf%lf%lf",&mw,&mi,&tw,&ti);
		if(mw == 0 && mi == 0 && ti == 0 && tw == 0)
			break;
		tw = 273 + tw;
		ti = 273 + ti;
		if(mw*cw*(tw-273) >= mi*ci*(273-ti) + mi*em)
		{
			x = (mw*cw*tw + mi*ci*ti - mi*em + mi*(273)*(cw-ci))/((mw+mi)*cw);
			printf("%.1lf g of ice and %.1lf g of water at %.1lf C\n", 0.0, mw+mi, x-273.0);
		}
		else if(mi*ci*(273-ti) >= mw*cw*(tw-273) + mw*em)
		{
			y = (mw*cw*tw + mi*ci*ti + mw*em + mw*(273)*(ci-cw))/((mw+mi)*ci);
			printf("%.1lf g of ice and %.1lf g of water at %.1lf C\n",mw+mi,0.0,y-273.0);
		}
		else
		{
			z = (mw*cw*(tw-273) - mi*ci*(273-ti))/em;
			printf("%.1lf g of ice and %.1lf g of water at %.1lf C\n",mi-z,mw+z,0.0);
		}
	}
}
