
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
  
	<title>{{ $titulo or 'AlphaImoveis'}}</title>

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



<!--Imagens em rotatividade -->
<div class="container" style="padding:20px;">
<div id="myCarousel" class="carousel slide" data-ride="carousel">

    <ol class="carousel-indicators">
        <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
        <li data-target="#myCarousel" data-slide-to="1"></li>
        <li data-target="#myCarousel" data-slide-to="2"></li>
    </ol>

    <div class="carousel-inner">

        <div class="item active">
            <img class="img-responsive center-block" src="css/assets/img/casa1.jpg" alt="casa1" style="width: 500px; height: 300px">
        </div>

        <div class="item">
            <img class="img-responsive center-block" src="css/assets/img/h1.jpg" alt="casa2" style="width: 500px; height: 300px">
        </div>

        <div class="item">
            <img class="img-responsive center-block" src="css/assets/img/h2.jpg" alt="casa3" style="width: 500px; height: 300px">
        </div>

    </div>

    <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
    <span class="glyphicon glyphicon-chevron-left"></span>
    <span class="sr-only">Previous</span>
</a>

    <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
    <span class="glyphicon glyphicon-chevron-right"></span>
    <span class="sr-only">Next</span>
</a>

</div><br><br>

</div>




<div class="container text-center" style="padding-bottom: 30px;">
<div class="row">
    <div class="col-md-4">
        <div class="well" style="border-radius: 1rem">
            <h2 class="text-center"><span class="label label-info">Publique</span></h2>
            <h3 class="text-center">Seu imóvel é anunciado a milhares de pessoas no nosso site.</h3>
        </div>
    </div>
    <div class="col-md-4">
        <div class="well" style="border-radius: 1rem">
            <h2 class="text-center"><span class="label label-info">Personalize</span></h2>
            <h3 class="text-center">Faça do seu produto, um marketing de sucesso, atraia interessados.</h3>
        </div>
    </div>
    <div class="col-md-4">
        <div class="well" style="height: 200px; border-radius: 1rem">
            <h2 class="text-center"><span class="label label-info">Sem Custos</span></h2>
            <h3 class="text-center">Negociando seu imóvel não cobramos nada pelo serviço.</h3>
        </div>
    </div>
</div>
<!--/row-->
</div>
<!--container-->









<footer style="background-color: #211b23; height: 150px;">


<div class="container text-center text-md-left">
<div class="row" style="padding-top: 20px">


    <div class="col-md-4" style="color: white;">
        <h5 class="text-uppercase mb-4 mt-3 font-weight-bold" >AIM</h5>
        <p>Alpha Imóveis é um projeto continuo que busca trazer o desejo de se adquirir um imóvel e facilidade, sem exigir custos adicionais por seus serviços.</p>
    </div>
    




<!--Copyright-->
<div class="footer-copyright py-3 text-center" style="color:white">
© 2018 Copyright:
<a href="index.php"> AlphaImoveis </a>
</div>
<!--/.Copyright-->

</footer>

</body>
</html>