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
    <link rel="stylesheet" href="{{ url('css/assets/css/planos.css') }}">
</head>
<body>

@yield('content')
<header style="padding-top:50px; padding-bottom:30px">
<nav class="navbar navbar-fixed-top" style="padding-left:0px; padding-right:20px; background-color: navy; ">

    <div class="navbar-header">
        <a class="navbar-brand" href="#"></a>
    </div>
    <ul class="nav navbar-nav">
        <li><a href="{{ url('/') }}">Página Inicial</a></li>
        <li><a href="{{ route('como-funciona.index') }}">Como Funciona</a></li>
        <li><a href="{{ route('planos.index') }}">Planos</a></li>
        <li><a href="{{ route('suporte.index') }}">Suporte</a></li>
    </ul>
    <ul class="nav navbar-nav navbar-right">
        <li><a href="{{ route('signup.index') }}"><span class="glyphicon glyphicon-user"></span> Sign Up</a></li>
        <li><a href="{{ route('login.index') }}"><span class="glyphicon glyphicon-log-in"></span> Login</a></li>
    </ul>

</nav>

</header>


<div class="price-table-wrapper">
  <div class="pricing-table">
    <h2 class="pricing-table__header">- BASICO -</h2>
    <h3 class="pricing-table__price">$15</h3>
    <a target="_blank" class="pricing-table__button" href="{{ route('login.index') }}">
      Adquira agora!
    </a>
    <ul class="pricing-table__list text-center">
      <li>30 day free trial</li>
      <li>50gb storage space</li>
      <li>20% discount</li>
      <li>24 hour support</li>
    </ul>
  </div>
  <div class="pricing-table featured-table">
    <h2 class="pricing-table__header">- MEDIO -</h2>
    <h3 class="pricing-table__price">$20</h3>
    <a target="_blank" class="pricing-table__button" href="{{ route('login.index') }}">
       Adquira agora!
    </a>
    <ul class="pricing-table__list">
      <li>40 day free trial</li>
      <li>100gb storage space</li>
      <li>25% discount</li>
      <li>24 hour support</li>
    </ul>
  </div>
  <div class="pricing-table">
    <h2 class="pricing-table__header">- PLUS -</h2>
    <h3 class="pricing-table__price">$25</h3>
    <a target="_blank" class="pricing-table__button" href="{{ route('login.index') }}">
       Adquira agora!
    </a>
    <ul class="pricing-table__list">
      <li>50 day free trial</li>
      <li>200gb storage space</li>
      <li>40% discount</li>
      <li>24 hour support</li>
    </ul>
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