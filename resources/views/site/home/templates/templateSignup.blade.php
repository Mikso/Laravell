<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
  
	<title>{{ $title or 'Sign Up'}}</title>

    <link rel="stylesheet" href="{{ url('css/assets/css/bootstrap.css') }}">
    <script src="{{ url('css/assets/js/jquery.js') }}"></script>
    <script src="{{ url('css/assets/js/bootstrap.js')}}"></script>
    <script src="{{ url('css/assets/js/mask.js')}}"></script>

</head>
<body>


<header style="padding-top:50px; padding-bottom:30px">
        <nav class="navbar navbar-fixed-top" style="padding-left:0px; padding-right:20px; background-color: navy; ">

            <div class="navbar-header">
                <a class="navbar-brand" href="#"></a>
            </div>
            <ul class="nav navbar-nav">
                <li><a href="{{ url('/') }}">Página Inicial</a></li>
                <li><a href="{{ url('/alpha-imoveis/como-funciona') }}">Como funciona</a></li>
                <li><a href="{{ route('suporte.index') }}">Suporte</a></li>
            </ul>
            <ul class="nav navbar-nav navbar-right">
                <li><a href="{{ url('/alpha-imoveis/login') }}"><span class="glyphicon glyphicon-log-in"></span> Login</a></li>
            </ul>

        </nav>

</header>

<div class="container" style="padding-top: 20px; padding-bottom: 200px; width: 70%">

<form action="{{ url('/alpha-imoveis/signup/create') }}" >
  <div class="form-row">
    <div class="form-group col-md-6">
      <label>Nome</label>
      <input type="text" name="nome" class="form-control" placeholder="Nome" required="true">
    </div>
    <div class="form-group col-md-6">
      <label>Sobrenome</label>
      <input type="text" name="sobrenome" class="form-control" placeholder="Sobrenome" required="true">
    </div>
  </div>
  
 <div class="form-row">
    <div class="form-group col-md-2">
      <label>Idade</label>
      <input type="text" name="idade" class="form-control" placeholder="Idade" required="true">
    </div>
    <div class="form-group col-md-3">
      <label>CPF</label>
      <input type="text"
      id="CPF" name="cpf" class="form-control" placeholder="CPF" required="true" maxlength="8">
    </div>
    <div class="form-group col-md-3">
      <label>CEP</label>
      <input type="text" id="CEP" name="cep" class="form-control" placeholder="CEP" required="true" maxlength="8">
    </div>
 
    </div>


 <div class="form-row">
     <div class="form-group col-md-5">
      <label>Email</label>
      <input type="email" name="email" class="form-control" placeholder="Email" required="true">
    </div>
     <div class="form-group col-md-5">
      <label>Senha</label>
      <input type="password" id="senha_info" name="senha" class="form-control" placeholder="Senha" required="true" minlength="5" maxlength="10">

<br>



 </div>
  


  </div>

<div class="container text-center" style="width: 50%">
    
<button type="submit" id="btn" class="btn btn-primary">Sign up</button>


</div>


  
 
</form>

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


<script>

// Mascara de entrada
$(document).ready(function(){
  $('#CPF').mask('999999-99');
  $('#CEP').mask('99999-999');

});


</script>


</body>
</html>