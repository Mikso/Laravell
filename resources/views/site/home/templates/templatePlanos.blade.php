@yield('content')
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
  
	<title>{{ $title or 'Planos'}}</title>

    <link rel="stylesheet" href="{{ url('css/assets/css/bootstrap.css') }}">
    <script src="{{ url('css/assets/js/jquery.js') }}"></script>
    <script src="{{ url('css/assets/js/bootstrap.js')}}"></script>
  
</head>
<body>


<header style="padding-top:50px; padding-bottom:30px">
        <nav class="navbar navbar-fixed-top" style="padding-left:0px; padding-right:20px; background-color: navy; ">

            <div class="navbar-header">
                <a class="navbar-brand" href="#"></a>
            </div>
            <ul class="nav navbar-nav">
        <li><a href="{{ url('/') }}">Página Inicial</a></li>
        <li><a href="{{ url('alpha-imoveis/como-funciona') }}">Como Funciona</a></li>
        <li><a href="{{ url('alpha-imoveis/planos') }}">Planos</a></li>
        <li><a href="{{ url('alpha-imoveis/suporte') }}">Suporte</a></li>
    </ul>
    <ul class="nav navbar-nav navbar-right">
        <li><a href="{{ url('alpha-imoveis/signup') }}"><span class="glyphicon glyphicon-user"></span> Sign Up</a></li>
        <li><a href="{{ url('alpha-imoveis/login') }}"><span class="glyphicon glyphicon-log-in"></span> Login</a></li>
    </ul>

        </nav>

</header>

<div class="container" style="height:100%">
  <div class="panel text-center" style="width: 30%;">
    <div class="panel-heading" style="
        background-color: #ffff00;
        font-size:30px;
        font-family: Open Sans;
        ">Standard

</div>
    
    <div class="header" style="
        color: white;
        background-color: #1f1f2e; 
        font-size:75px;
    	border-radius: 0px 0px 5px 5px;
        font-family:'Open Sans';
        font-style:condense;
    ">
			<span>$</span>29<sup>99</sup>
            <p class="month" style="
            font-size:20px;
            color: #ccccb3;
            padding-bottom: 20px;
            ">per month</p>
            
    </div>
    


    <div class="panel-body" style="color: white ;background-color: #1f1f2e; font-size:20px" >Crie até 3 anúncios</div>
    <div class="panel-body" style="color: white ;background-color: #1f1f2e; font-size:20px" >Exiba até 4 fotos</div>
      <button class="btn btn-primary" style="
            width: 100%;
            border-radius: 0px 0px 5px 5px;
      ">Enviar</button>

  </div>
</div>






 

<footer style="background-color: #211b23; height: 150px;">

    
    <div class="container text-center text-md-left">
        <div class="row" style="padding-top: 20px">


            <div class="col-md-4" style="color: white;">
                <h5 class="text-uppercase mb-4 mt-3 font-weight-bold" >AIM</h5>
                <p>Alpha Imóveis é um projeto continuo que busca trazer o desejo de se adquirir um imóvel e facilidade, sem exigir custos adicionais por seus serviços.</p>
            </div>
            

    
    <!--Copyright-->
    <div class="footer-copyright py-3 text-center" style="color:white">
        © 2018 Copyright
          </div>
    <!--/.Copyright-->

</footer>



</body>
</html>